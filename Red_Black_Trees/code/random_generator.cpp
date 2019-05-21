#ifndef __RANDOM_GENERATOR_CC__
#define __RANDOM_GENERATOR_CC__

#include "random_generator.h"
#include <sys/times.h>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>

bool random_generator::initialized = false;

void random_generator::seed(unsigned int r)
{ /*<<<*/
  if (initialized)
    return;

/*
 * integer part
 */
  unsigned int s;
  struct tms t_info;

/*
 * Use random device to find initial value for s
 */
  s = r; 	/* avoid uninitialized error */
  s ^= static_cast<unsigned int>(times(&t_info));
  s *= static_cast<unsigned int>(getpid());
  s += static_cast<unsigned int>(getppid());
  s -= static_cast<unsigned int>(time(0));

  SRANDOM(s);

  initialized = true;
} /*>>>*/

/*
 * random number production via operator >>
 */
random_generator& operator >> (random_generator& rg, int& i)
{ /*<<<*/
  i = static_cast<int>(RANDOM());

  return rg;
} /*>>>*/

random_generator& operator >> (random_generator& rg, long& l)
{ /*<<<*/
  l = static_cast<long>(RANDOM());

  return rg;
} /*>>>*/

random_generator& operator >> (random_generator& rg, double& d)
{ /*<<<*/
  double t1, t2;

  t1 = RAND_MAX;
  t1 += 1.0;
  t1 *= RANDOM();
  t1 += RANDOM();

  t2 = RAND_MAX;
  t2 += 1.0;
  t2 *= RANDOM();
  t2 += RANDOM();

  if (t1 < t2)
    d = t1/t2;
  else
    {
      if (t2 < t1)
	d = t2/t1;
      else
	d = 0.0;
    }

  return rg;
} /*>>>*/


char* random_generator::random_string(int r_max_n, int& r_n)
{ /*<<<*/
  char* st;
  int ch;

/*
 * detemine string size > 0 <= r_max_n
 * randomly select 0 < r_n <= r_max_n
 * allocate r_n+1 char -> set 0 from n to r_n!
 */
  r_max_n = (r_max_n > 1) ? r_max_n : 2;

  *this >> r_n;
  r_n = (r_n % (r_max_n - 1)) + 1;

  st = new char[r_n+1];

/*
 * set first n characters at random from 'a' ... 'z'
 */
  for (int i = 0; i < r_n; i++)
    {
      *this >> ch;

      st[i] = 'a' + static_cast<char>(ch % 26);
    }

/*
 * string end
 */
  st[r_n] = 0;

  return st;

} /*>>>*/

#endif
