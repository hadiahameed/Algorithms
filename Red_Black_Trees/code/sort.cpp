#include <cstdio>
#include <cstdlib>
#include <iostream>


#include "sort.h"

using namespace std;

/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is 
 *    greater than the i-th element.
 */
bool check_sorted(int* A, int l, int r)
{
  for (int i = l+1; i < r; i++){
    if (A[i-1] > A[i])
    {
      cout << "i: " << i << endl;
      cout << "A[i-1]: " << A[i-1] << endl;
      cout << "A[i]: " << A[i] << endl;
      return false;
    }
  }
  return true;
}

/*
 * generate sorted/reverse/random arrays 
 */
int* create_reverse_sorted(int n)
{
  int* n_array;

  n_array = new int[n];
  for (int i = 0; i < n; i++)
    n_array[i] = n-i;

  return n_array;
}


int* create_sorted(int n)
{
  int* n_array;

  n_array = new int[n];
  for (int i = 0; i < n; i++)
    n_array[i] = i;

  return n_array;
}


int* create_random(int n)
{
  random_generator rg;
  int* n_array;

  n_array = new int[n];
  for (int i = 0; i < n; i++){
    rg >> n_array[i];
  }

  return n_array;
}

void remove_array(int* n_array){
  delete[] n_array;
}

