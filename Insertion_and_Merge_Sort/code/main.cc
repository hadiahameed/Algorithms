#include <cstdio>
#include <cstdlib>

#include <sort.h>
#include <timer.h>
#include <random_generator.h>

int main(int argc, char* argv[])
{
  random_generator rg;
  timer t;
  int n, m, d, a;
  
  if (argc > 1)
    { 
      m = atoi(argv[1]);
      m = (m < 1) ? 1 : m;
    }
  else
    {
      cout << "hw1: [m] [n] [direction]" << endl;
      cout << "[m]              size of the random integer vector array" << endl;
      cout << "[n]              dimension of integer vector array" << endl;
      cout << "[direction]      0: random" << endl;
      cout << "                 1: sorted" << endl;
      cout << "                 -1: reverse sorted" << endl;
      cout << endl;
      return 0;
    }

  if (argc > 2)
    {
      n = atoi(argv[2]);
      n = (n < 0) ? 0 : n;
    }
  else
    n = 0;

  if (argc > 3)
    d = atoi(argv[3]);
  else
    d = 0;

  int** input_array;
  int rows = m;
  int columns = n;
  int sum = 0;

/****************************************************************************
-------------------------NAIVE INSERTION SORT----------------------------
*****************************************************************************/
cout << "Running naive insertion sort for array with "<<rows<<" rows and "<<columns<<" columns:"<<endl;
for(int iter=0;iter<10;iter++){ 
  if (d == 0)
      input_array = create_random_ivector(n, m, true);
    else
      {
        if (d < 0)
          input_array = create_reverse_sorted_ivector(n, m);
        else
          input_array = create_sorted_ivector(n, m);
    }
    t.start();
       insertion_sort(input_array, columns, 0, rows-1);
    t.stop();
    if (check_sorted(input_array, n, 0, m-1))
      cout << "Sorted!" << endl;
    else
      cout << "Not sorted!" << endl;
    sum += t.real();
    remove_ivector(input_array,m);
    
 }
 sum = sum/10;
 cout << "Timer (sort) nIS: " << sum << endl;

 
 

/****************************************************************************
-------------------------EFFICIENT INSERTION SORT----------------------------
*****************************************************************************/
//Do Improved insertion sort
 cout << "Running efficient insertion sort for array with "<<rows<<" rows and "<<columns<<" columns:"<<endl;
 for(int iter=0;iter<10;iter++){ 
  if (d == 0)
      input_array = create_random_ivector(n, m, true);
    else
      {
        if (d < 0)
          input_array = create_reverse_sorted_ivector(n, m);
        else
          input_array = create_sorted_ivector(n, m);
    }
    t.start();
      efficient_insertion_sort(input_array, columns, rows-1);
    t.stop();
    if (check_sorted(input_array, n, 0, m-1))
      cout << "Sorted!" << endl;
    else
      cout << "Not sorted!" << endl;
    sum += t.real();
    remove_ivector(input_array,m);
    
 }
 sum = sum/10;
 cout << "Timer (sort) eIS: " << sum << endl;

/****************************************************************************
-------------------------MERGE SORT----------------------------
*****************************************************************************/
 /*int nn[4] = {5000,1000,25000,50000};
 int mm[3] = {10,25,50};
 int dd[3] = {0,1,-1};
 for(int kk=0;kk<3;kk++){
  d = dd[kk];
  for (int ii=0;ii<3;ii++){
    columns = mm[ii];
    for (int jj=0;jj<2;jj++){
      rows = nn[jj];*/
      sum = 0;
      cout << "Running merge sort for array with "<<rows<<" rows and "<<columns<<" columns:"<<endl;
      for(int iter=0;iter<10;iter++){ 
        if (d == 0)
            input_array = create_random_ivector(columns,rows, true);
          else
            {
              if (d < 0)
                input_array = create_reverse_sorted_ivector(columns, rows);
              else
                input_array = create_sorted_ivector(columns, rows);
          }
          t.start();
            merge_sort_main(input_array, columns, 0, rows-1);
          t.stop();
          if (check_sorted(input_array, columns, 0, rows-1))
            cout << "Sorted!" << endl;
          else
            cout << "Not sorted!" << endl;
          sum += t.real();
          remove_ivector(input_array,rows);
          
      }
      sum = sum/10;
      cout << "Timer (sort) mS: " << sum << endl;
      /*
    }
  }
 }
 */


 
 
/*check whether or not the algorithm sorted the array
  output the first 20 elements for debugging purposes*/

/*for (int i = 0; (i < m) && (i < 20); i++)
    {
      cout << "[ ";
      for (int j = 0; j < n; j++)
	cout << input_array[i][j] << " ";
      cout << "]" << endl;
    }
  cout << endl;
*/

  return 0;
}

