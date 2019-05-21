#ifndef __SORT_H__
#define __SORT_H__

#include <random_generator.h>

using namespace std;

int ivector_length(int*, int);
int* arrayOfvectorLengths(int**,int,int);
void insertion_sort(int**, int, int, int);
void efficient_insertion_sort(int**, int,int);
void merge(int**, int*, int, int, int, int);
void merge_sort(int**, int*, int, int, int);
void merge_sort_main(int**, int, int, int);

bool check_sorted(int**, int, int, int);

int** create_ivector(int, int);
int** create_sorted_ivector(int, int);
int** create_reverse_sorted_ivector(int, int);
int** create_random_ivector(int, int, bool=false);

void remove_ivector(int**, int);


#endif
