#include <cstdio>
#include <cstdlib>
#include <sort.h>
#include <math.h>
#include <limits>

int ivector_length(int* v, int n)
{
  int sum;

  sum = 0;
  for (int i = 0; i < n; i++)
    sum += (v[i] < 0) ? -v[i] : v[i];

  return sum;
}

//calculates L1-norm of the vector in each row of A
//total number of vectors = rows (m)
//total number of elements in a vector = columns (n)
int* arrayOfvectorLengths(int** A,int rows,int columns){
  int* temp = new int[rows+1];
  for(int j =0;j<=rows;j++){
    temp[j] = ivector_length(A[j], columns);
  }
  return temp;
}

/*
 * Naive insertion sort
 */
void insertion_sort(int** A, int n, int l, int r)
{ 
  register int i;
  int* key;

  for (int j = l+1; j <= r; j++)
    {
      key = A[j];
      i = j - 1;

      while ((i >= l) && (ivector_length(A[i], n) > ivector_length(key, n)))
        {
	  A[i+1] = A[i];
	  i = i - 1;
	}

      A[i+1] = key;
    }
}
/*
  Improved and efficient Insertion Sort
*/
void efficient_insertion_sort(int** A, int columns,int rows)
{ 
  int* temp = arrayOfvectorLengths(A,rows,columns);
  register int i;
  int* key1;
  int key2;

  for (int j = 1; j <= rows; j++)
    {     
      key1 = A[j];
      key2 = temp[j];
      i = j - 1;

      while ((i >= 0) && (temp[i] > key2))
        {
              temp[i+1] = temp[i];
	            A[i+1] = A[i];
	            i = i - 1;
	      }

      A[i+1] = key1;
      temp[i+1] = key2;
    }
    delete[] temp; 
}



/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is 
 *    greater than the i-th element.
 */
bool check_sorted(int** A, int n, int l, int r)
{
  for (int i = l+1; i <= r; i++)
    if (ivector_length(A[i-1], n) > ivector_length(A[i], n))
      return false;
  return true;
}


/*
 * generate sorted/reverse/random arrays of type hw1type
 */
int** create_ivector(int n, int m)
{
  //pointer to an integer array
  int** iv_array;

  //pointer to an m-sized dynamically allocated integer array
  iv_array = new int*[m];
  for (int i = 0; i < m; i++)
    //each element has pointer to an n-sized vector
    iv_array[i] = new int[n];

  return iv_array;
}

void remove_ivector(int** iv_array, int m)
{
  for (int i = 0; i < m; i++)
    delete[] iv_array[i];
  delete[] iv_array;
}

int** create_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = (i+j)/n;

  return iv_array;
}

int** create_reverse_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = ((m-i)+j)/n;

  return iv_array;
}

int** create_random_ivector(int n, int m, bool small)
{
  random_generator rg;
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      {
	      rg >> iv_array[i][j];
        if (small)
          iv_array[i][j] %= 100;
        else
          iv_array[i][j] %= 65536;
      }

  return iv_array;
}

/*
  Merge Sort
*/
void merge(int** A, int* vector_lengths, int start_index, int q, int rows, int columns)
{ 
    
    int n1 = q - start_index + 1;
    int n2 = rows - q;

    int* L = new int[n1+1];
    int* R = new int[n2+1];
    int** LA = new int*[n1];
    for(int i = 0; i < n1; ++i){
      LA[i] = new int[columns];
      L[i] = vector_lengths[start_index + i];
      LA[i] = A[start_index + i];
    }
    int** RA = new int*[n2];
    for(int j = 0; j < n2; ++j){
      RA[j] = new int[columns];
      R[j] = vector_lengths[q + j + 1];

      RA[j] = A[q + j + 1];
    }


    L[n1] = std::numeric_limits<int>::max();
    R[n2] = std::numeric_limits<int>::max();
    int i = 0;
    int j = 0;
    for (int k = start_index; k <= rows; k++) {
      if (L[i]<=R[j]) {
        vector_lengths[k] = L[i];
        A[k] = LA[i];
        i = i + 1;
      }
      else {
        vector_lengths[k] = R[j];
        A[k] = RA[j];
        j = j + 1;
      }
    }
  
    delete[] L;
    delete[] R; 
}
void merge_sort(int** A, int *vector_lengths, int start_index, int rows, int columns)
{ 
  int q;
	if (start_index < rows) //p<r
	{
		q = floor((start_index + rows) / 2);
		// Split the data into two half.
		merge_sort(A, vector_lengths, start_index, q,columns);
		merge_sort(A, vector_lengths, q + 1, rows,columns);

		// Merge them to get sorted output.
		merge(A,vector_lengths, start_index, q,rows,columns);
	}
}

void merge_sort_main(int** A, int columns, int start_index, int rows){
  int* vector_lengths = arrayOfvectorLengths(A,rows,columns);
  merge_sort(A,vector_lengths,start_index,rows,columns);
  delete[] vector_lengths;

}
