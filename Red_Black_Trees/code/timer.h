

#ifndef __TIMER_H__
#define __TIMER_H__

/*
 * dummy 
 */
#define HAVE_POSIX_TIMES
#undef HAVE_GETRUSAGE


#include <iostream>
#include <list>
#include <string>

#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/times.h>

using namespace std;

class timer 
{ /*<<<*/
  private:
    static const double 		t_granularity;
    static const double 		t_granularity_min;
    static const double 		t_granularity_hour;
    static const double 		t_granularity_day;

    static double 			t_granularity_factor;
    static long 			t_clock_ticks;
  
    struct timeval			t_tv;
    struct timezone			t_tz;

    long 				t_user;
    long				t_sys;

    long 				t_user_total;
    long				t_sys_total;
    long				t_real_total;

    bool 				t_print_mode;

/*
 * global timers
 */
    static list< pair<timer*,string> >	t_gt;
  
  public:
    timer();
    timer(const timer&);
    ~timer();

    static long clock_ticks();

    void set_print_mode_time()
      { t_print_mode = true; }
    void set_print_mode_hms()
      { t_print_mode = false; }

    void start();
    void stop();
    void cont();

    void reset();

    long user() const
      { return t_user_total; }
    long sys() const
      { return t_sys_total; }
    long real() const
      { return t_real_total; }

/*
 * operators
 */
    timer& operator = (const timer&);

    timer operator + (const timer&);
    timer operator - (const timer&);
    timer operator / (double);

/*
 * output
 */
    void print(ostream& = cout) const;

    friend ostream& operator << (ostream&, const timer&);


/*
 * global timers
 */
    static void gt_init();
    static timer* gt_add(string);
    static list< pair<timer*,string> >* gt_access();
}; /*>>>*/


#endif

/*
 * we undef all macros to allow for redefinition
 * on a per file basis depending on __GT__
 */
#ifndef __gt_init__
#define	__gt_init__					\
  timer::gt_init()
#endif

#ifndef __gt_clear__
#define	__gt_clear__					\
  timer::gt_init()
#endif

#undef __gt_decl__
#undef __gt_add__
#undef __gt_measure__
#undef __gt_summary__

#ifdef __GT__

#define __gt_decl__(TM)					\
  timer* TM;

#define __gt_add__(TM,DESC)				\
  TM = timer::gt_add(DESC)

#define __gt_measure__(TM,CODE)				\
  TM->cont();						\
  CODE							\
  TM->stop()

#define __gt_summary__					\
{							\
  list< pair<timer*,string> >*	l_gt;			\
							\
  l_gt = timer::gt_access();				\
							\
  if (l_gt->size() > 0)					\
    {							\
      cout << endl;					\
      cout << "***** gt Summary ******" << endl;	\
      for (list< pair<timer*,string> >::iterator __i = 	\
	   l_gt->begin(); __i != l_gt->end(); __i++)	\
	cout << "Timer (\"" << __i->second << "\"): "	\
	     << *(__i->first) << endl;			\
      cout << "***** gt Summary ******" << endl;	\
      cout << endl;					\
    }							\
} 

#else

#define __gt_decl__(TM)

#define __gt_add__(TM,DESC)				\
  do { } while (0)			

#define __gt_measure__(TM,CODE)				\
  CODE

#define __gt_summary__					\
  do { } while (0)			

#endif

