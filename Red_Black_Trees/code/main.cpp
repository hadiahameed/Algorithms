#include <cstdio>
#include <cstdlib>

#include "sort.h"
#include "bs_tree.h"
#include "rb_tree.h"
#include "timer.h"
#include "random_generator.h"

int main(int argc, char* argv[])
{ 
  random_generator rg;
  timer t;
  int n, d, a;
  
  if (argc > 1)
    { 
      n = atoi(argv[1]);
      n = (n < 0) ? 0 : n;
    }
  else
    {
      cout << "hw4: [n] [direction]" << endl;
      cout << "[n]              size of the random integer array" << endl;
      cout << "[direction]      0: random" << endl;
      cout << "                 1: sorted" << endl;
      cout << "                 -1: reverse sorted" << endl;
      cout << endl;
      return 0;
    }

  if (argc > 2)
    d = atoi(argv[2]);
  else
    d = 0;

  int sum = 0;
  int iterations = 10;
  int counter_duplicates_BST = 0;
  int counter_duplicates_RBT = 0;
  int counter_right_rotate = 0;
  int counter_left_rotate = 0;
  int counter_case1 = 0;
  int counter_case2 = 0;
  int counter_case3 = 0;

  cout<<"------------------------------------"<<endl;
  cout << "Parameters:"<<endl;
  cout<<"------------------------------------"<<endl;
  cout<<endl;
  cout<<"Number of iterations: "<<iterations<<endl;
  cout<<"Input Size: "<<n<<endl;
  cout<<"Direction: "<<d<<endl;

  cout<<endl;

  cout<<"*************************************"<<endl;
  cout << "Sorting using Binary Search Tree (BST)"<<endl;
  cout<<"*************************************"<<endl;
  
  for(int iter=0;iter<iterations;iter++){ 
		bs_tree* BST = new bs_tree();
    int* ia;
  	if (d == 0)
      ia = create_random(n);
  	else
  	{
    	if (d < 0)
      	ia = create_reverse_sorted(n);
    	else
      	ia = create_sorted(n);
  	}
    t.start();
  	  BST->insert(ia,n);
      int n_prime = n - BST->get_counter_duplicate();
      /*no need to dealloacte "arr" since we are deallocating the original array 
          in the destructor of bs_tree*/
      int* arr = new int[n_prime];   
      arr = BST->inorder_output(n_prime);
    t.stop();
    /*for (int ij =0; ij < n_prime; ij ++){
      if(ij==n_prime-1)cout<<arr[ij]<<endl;
      else cout<<arr[ij]<<" , ";  
    }*/
  
		if (!check_sorted(arr, 0, n_prime))
      cout << "Not Sorted!" << endl;
    
    counter_duplicates_BST += BST->get_counter_duplicate();
		delete BST;
    remove_array(ia);
  	sum += t.real();   
  }

 sum = sum/iterations;
 counter_duplicates_BST = counter_duplicates_BST/iterations;
 cout<<endl;
 cout<<"Average counter_duplicates_BST: "<<counter_duplicates_BST<<endl;
 cout << "---*---(Timer (sort) BST)---*---: " << sum << " ms "<<endl;


 /*************************************************************************/
sum = 0;
cout<<endl;
cout<<"*************************************"<<endl;
cout << "Sorting using Red Black Tree (RBT)"<<endl;
cout<<"*************************************"<<endl;
  
  for(int iter=0;iter<iterations;iter++){ 
		rb_tree* RBT = new rb_tree();
    int* ia;
  	if (d == 0)
      ia = create_random(n);
  	else
  	{
    	if (d < 0)
      	ia = create_reverse_sorted(n);
    	else
      	ia = create_sorted(n);
  	}
    t.start();
  	  RBT->insert(ia,n);
      int n_prime = n - RBT->get_counter_duplicate();
      /*no need to dealloacte "arr" since we are deallocating the original array 
          in the destructor of rb_tree*/
      int* arr = new int[n_prime];
      arr = RBT->inorder_output(n_prime);
    t.stop();
    /*for (int ij =0; ij < n_prime; ij ++){
      if(ij==n_prime-1)cout<<arr[ij]<<endl;
      else cout<<arr[ij]<<" , ";  
    }*/
  	
		if (!check_sorted(arr, 0, n_prime))
      cout << "Not Sorted!" << endl;
    
    counter_duplicates_RBT += RBT->get_counter_duplicate();
    counter_case1 += RBT->get_counter_case1();
    counter_case2 += RBT->get_counter_case2();
    counter_case3 += RBT->get_counter_case3();
    counter_left_rotate += RBT->get_counter_left_rotate();
    counter_right_rotate += RBT->get_counter_right_rotate();
		delete RBT;
    remove_array(ia);
  	sum += t.real();   
  }
 counter_duplicates_RBT = counter_duplicates_RBT/iterations;
 counter_case1 = counter_case1/iterations;
 counter_case2 = counter_case2/iterations;
 counter_case3 = counter_case3/iterations;
 counter_left_rotate = counter_left_rotate/iterations;
 counter_right_rotate = counter_right_rotate/iterations;
 sum = sum/iterations;
 cout<<endl;
 cout<<"Average counter_duplicates_RBT: "<<counter_duplicates_RBT<<endl;
 cout<<"Average counter_case1: "<<counter_case1<<endl;
 cout<<"Average counter_case2: "<<counter_case2<<endl;
 cout<<"Average counter_case3: "<<counter_case3<<endl;
 cout<<"Average counter_left_rotate: "<<counter_left_rotate<<endl;
 cout<<"Average counter_right_rotate: "<<counter_right_rotate<<endl;
 cout<<counter_duplicates_RBT<<" "<<counter_case1<<" "<<counter_case2<<" "<<counter_case3<<" "<<counter_left_rotate<<" "<<counter_right_rotate<<endl;
 cout << "---*---(Timer (sort) RBT)---*---: " << sum <<" ms "<<endl;

//Checking inserion with duplicates
cout<<endl;
cout<<"------------------------------------"<<endl;
cout << "Test Cases"<<endl;
cout<<"------------------------------------"<<endl;
cout<<endl;
cout << "a) BST"<<endl;
cout<<"------------------------------------"<<endl;
  bs_tree* BST = new bs_tree();
  int m = 22;
  int input_array [22] = {26,26,17,17,41,14,21,30,47,10,16,19,23,28,38,7,12,15,20,35,39,3};
  BST->insert(input_array,m);
  int m_prime = m - BST->get_counter_duplicate();
  int* arr = new int[m_prime];
  arr = BST->inorder_output(m_prime);
  cout<<"Printing Sorted array:"<<endl;
  for (int ij =0; ij < m_prime; ij ++){
    if(ij==m_prime-1)cout<<arr[ij]<<endl;
    else cout<<arr[ij]<<" , "; 
  }
  if (!check_sorted(arr, 0, m_prime))
      cout << "Not Sorted!" << endl;
  delete BST;

  cout<<endl;
  cout << "b) RBT"<<endl;
  cout<<"------------------------------------"<<endl;
  rb_tree* RBT = new rb_tree();;
  RBT->insert(input_array,m);
  m_prime = m - RBT->get_counter_duplicate();
  arr = new int[m_prime];
  arr = RBT->inorder_output(m_prime);
  cout<<"Printing Sorted array:"<<endl;
  for (int ij =0; ij < m_prime; ij ++){
    if(ij==m_prime-1)cout<<arr[ij]<<endl;
    else cout<<arr[ij]<<" , "; 
  }
  if (!check_sorted(arr, 0, m_prime))
      cout << "Not Sorted!" << endl;
  cout<<endl;
  cout << "Testing Property 5: Black Height"<<endl;
  cout<<"------------------------------------"<<endl;
  int bh = RBT->rb_tree_test_function();
  cout<<"Black Height of the root is: "<<bh<<endl;
  cout<<endl;
  delete RBT;
  return 0;
}

  
