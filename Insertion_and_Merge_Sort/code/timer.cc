/** @file */
/*
 * vim:set fdm=marker:
 * vim:set fmr=<<<,>>>
 *
 */

#ifndef __TIMER_CC__
#define __TIMER_CC__

#include <timer.h>

using namespace std;


/*
 * some constants
 */
const double timer::t_granularity 	= 1000.0;
const double timer::t_granularity_min 	= 60.0 * t_granularity;
const double timer::t_granularity_hour 	= 60.0 * t_granularity_min;
const double timer::t_granularity_day 	= 24.0 * t_granularity_hour;

double timer::t_granularity_factor 	= 0;
long timer::t_clock_ticks 		= 0;

list< pair<timer*,string> > timer::t_gt;

long timer::clock_ticks()
{ /*<<<*/
  if (!t_clock_ticks) 
    {
      t_clock_ticks = sysconf(_SC_CLK_TCK);
      t_granularity_factor = t_granularity/t_clock_ticks;
    }

  return t_clock_ticks;
} /*>>>*/

/*
 * constructor/destructor
 */
timer::timer()
{ /*<<<*/
  t_user = 0;
  t_sys = 0;

  t_user_total = 0;
  t_sys_total = 0;
  t_real_total = 0;

  t_print_mode = true;

  if (!t_clock_ticks) 
    {
      t_clock_ticks = sysconf(_SC_CLK_TCK);
      t_granularity_factor = t_granularity/t_clock_ticks;
    }
} /*>>>*/

timer::timer(const timer& t)
{ /*<<<*/
  t_user = t.t_user;
  t_sys = t.t_sys;

  t_user_total = t.t_user_total;
  t_sys_total = t.t_sys_total;
  t_real_total = t.t_real_total;

  t_print_mode = t.t_print_mode;
} /*>>>*/

timer::~timer()
{ }


void timer::start()
{ /*<<<*/
#ifdef HAVE_POSIX_TIMES
  struct tms buffer;
  
  times(&buffer);

  t_user = (long )((buffer.tms_utime+buffer.tms_cutime) * t_granularity_factor);
  t_sys = (long )((buffer.tms_stime+buffer.tms_cstime) * t_granularity_factor);
#else
#ifdef HAVE_GETRUSAGE
  struct rusage tru_buffer;

  getrusage(0, &tru_buffer);

  t_user = (long )(tru_buffer.ru_utime.tv_sec * 1000 + tru_buffer.ru_utime.tv_usec / 1000);
  t_sys  = (long )(tru_buffer.ru_stime.tv_sec * 1000 + tru_buffer.ru_stime.tv_usec / 1000);
#endif
#endif

  gettimeofday(&t_tv, &t_tz);

  reset();
} /*>>>*/

void timer::stop()
{ /*<<<*/
#ifdef HAVE_POSIX_TIMES
  struct tms buffer;

  times(&buffer);

  t_user_total += (long )((buffer.tms_utime+buffer.tms_cutime) * t_granularity_factor) - t_user;
  t_sys_total += (long )((buffer.tms_stime+buffer.tms_cstime) * t_granularity_factor) - t_sys;
#else
#ifdef HAVE_GETRUSAGE
  struct rusage tru_buffer;

  getrusage(0, &tru_buffer);


  t_user_total += (long )(tru_buffer.ru_utime.tv_sec * 1000 + 
			  tru_buffer.ru_utime.tv_usec/1000) - t_user;
  t_sys_total  += (long )(tru_buffer.ru_stime.tv_sec * 1000 + 
			  tru_buffer.ru_stime.tv_usec/1000) - t_sys;
#endif
#endif


  struct timeval l_tv;
  struct timezone l_tz;

  gettimeofday(&l_tv, &l_tz);

  t_real_total += ((l_tv.tv_sec-t_tv.tv_sec)*1000)+
                   (l_tv.tv_usec/1000)-(t_tv.tv_usec/1000);

} /*>>>*/

void timer::cont()
{ /*<<<*/
#ifdef HAVE_POSIX_TIMES
  struct tms buffer;

  times(&buffer);

  t_user = (long )((buffer.tms_utime+buffer.tms_cutime) * t_granularity_factor);
  t_sys = (long )((buffer.tms_stime+buffer.tms_cstime) * t_granularity_factor);

#else
#ifdef HAVE_GETRUSAGE
  struct rusage tru_buffer;

  getrusage(0, &tru_buffer);

  t_user = (long )(tru_buffer.ru_utime.tv_sec * 1000 + tru_buffer.ru_utime.tv_usec / 1000);
  t_sys  = (long )(tru_buffer.ru_stime.tv_sec * 1000 + tru_buffer.ru_stime.tv_usec / 1000);
#endif
#endif


  gettimeofday(&t_tv, &t_tz);
} /*>>>*/

void timer::reset()
{ /*<<<*/
  t_user_total = 0;
  t_sys_total = 0;
  t_real_total = 0;
} /*>>>*/

/*
 * operators
 */
timer& timer::operator = (const timer& a)
{ /*<<<*/
  t_user = a.t_user;
  t_sys = a.t_sys;

  t_user_total = a.t_user_total;
  t_sys_total = a.t_sys_total;
  t_real_total = a.t_real_total;

  t_print_mode = a.t_print_mode;

  return *this;
} /*>>>*/

timer timer::operator + (const timer& a)
{
  timer c;

  c.t_user = t_user + a.t_user;
  c.t_sys = t_sys + a.t_sys;

  c.t_user_total = t_user_total + a.t_user_total;
  c.t_sys_total = t_sys_total + a.t_sys_total;
  c.t_real_total = t_real_total + a.t_real_total;

  return c;
}

timer timer::operator - (const timer& a)
{
  timer c;

  c.t_user = t_user - a.t_user;
  c.t_sys = t_sys - a.t_sys;

  c.t_user_total = t_user_total - a.t_user_total;
  c.t_sys_total = t_sys_total - a.t_sys_total;
  c.t_real_total = t_real_total - a.t_real_total;

  if (c.t_user < 0) 
    c.t_user = 0;
  
  if (c.t_sys < 0)
    c.t_sys = 0;

  if (c.t_user_total < 0) 
    c.t_user_total = 0;

  if (c.t_sys_total < 0) 
    c.t_sys_total = 0;

  if (c.t_real_total < 0) 
    c.t_real_total = 0;

  return c;
}

timer timer::operator / (double d)
{
  timer c;

  if (d > 0.0)
    {
      c.t_user = (long )(t_user / d);
      c.t_sys = (long )(t_sys / d);
      c.t_user_total = (long )(t_user_total / d);
      c.t_sys_total = (long )(t_sys_total / d);
      c.t_real_total = (long )(t_real_total / d);
    }
  else
    c = *this;

  return c;
}


/*
 * output
 */
void timer::print(ostream& out) const
{ /*<<<*/
  if (t_print_mode)
    {
      out << real() << "ms real\t";
      out << user() << "ms user\t";
      out << sys() << "ms sys";
    }
  else
    {
      long d, h, m, s;
      long rt;

      rt = real();

      if (rt) 
	{
	  d = (long )(rt / t_granularity_day);
	  if (d) 
	    {
	      out << d << " day ";
	      rt -= (long )(d * t_granularity_day);
	    }
    
	  h = (long )(rt / t_granularity_hour);
	  if (h) 
	    {
	      out << h << " hour ";
	      rt -= (long )(h * t_granularity_hour);
	    }
    
	  m = (long )(rt / t_granularity_min);
	  if (m) 
	    {
	      out << m << " min ";
	      rt -= (long )(m * t_granularity_min);
	    }
    
	  s = (long )(rt / t_granularity);
	  if (s) 
	    {
	      out << s << " sec ";
	      rt -= (long )(s * t_granularity);
	    }

	  if (rt)
	    out << rt << " msec";
	}
  
      else 
	out << "0 msec";
    }
} /*>>>*/

ostream& operator << (ostream& out, const timer& t)
{ /*<<<*/
  t.print(out);
  
  return out;
} /*>>>*/

/*
 * global timer
 */
void timer::gt_init()
{ /*<<<*/
  for (list< pair<timer*,string> >::iterator i = 
       t_gt.begin(); i != t_gt.end(); i++)
    delete i->first;

  t_gt.clear();
} /*>>>*/

timer* timer::gt_add(string desc)
{ /*<<<*/
  pair<timer*,string> n_p;

  n_p.first = new timer();
  n_p.second = desc;

  t_gt.push_back(n_p);

  return n_p.first;
} /*>>>*/

list< pair<timer*,string> >* timer::gt_access()
{ return &t_gt; }

#endif
