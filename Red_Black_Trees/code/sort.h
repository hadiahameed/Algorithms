#ifndef __SORT_H__
#define __SORT_H__

#include "random_generator.h"

bool check_sorted(int*, int, int);

int* create_sorted(int);
int* create_reverse_sorted(int);
int* create_random(int);

void remove_array(int*);


#endif
