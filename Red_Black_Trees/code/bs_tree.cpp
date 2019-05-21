
#include "bs_tree.h"
#include <iostream>

using namespace std;

/*
 * constructor/destructor
 */
bs_tree::bs_tree()
{
/*
 * root of bs tree
 */
  T_root = new bs_tree_node();
  T_root = nullptr;
  counter_duplicate = 0;
  array = new int[1];

}

bs_tree::~bs_tree()
{ /*<<<*/ 
/*
 * delete nil element and all other allocated nodes
 */
  remove_all(T_root);
  delete[] array;
} /*>>>*/

void bs_tree::insert(int* key_array, int n)
{ /*<<<*/
  for (int i = 0; i < n; i++){
    insert(key_array[i]);
  }
} /*>>>*/

void bs_tree::insert(int key)
{ /*<<<*/
/*
 * wrapper around insert
 * -> creates black node with key
 * -> inserts node
 */
  bs_tree_node* z;

  z = new bs_tree_node;
  z->key = key;

  insert(z);
} /*>>>*/

void bs_tree::insert(bs_tree_node* z)
{ /*<<<*/
/*
 * binary tree type insert 
 * -> search position, insert new node
 * -> fix properties after insert
 */
  bs_tree_node* x;
  bs_tree_node* y;

  y = nullptr;
  x = T_root;
  while (x != nullptr)
    {
      y = x;
      if (z->key == x->key){
        counter_duplicate = counter_duplicate + 1;
        return;
      }
      if (z->key < x->key)
	      x = x->left;
      else
	      x = x->right;
    }

  z->p = y;
  if (y == nullptr)
    T_root = z;
  else
    {
      if (z->key < y->key)
	      y->left = z;
      else
	      y->right = z;
    }
  z->left = nullptr;
  z->right = nullptr;
} /*>>>*/


int* bs_tree::inorder_output(int n) {
  if(array){
    delete[] array;
  }
  array = new int[n];
  array_index = 0;
  inorder_output(T_root, 1);
  return array;
}

void bs_tree::inorder_output(bs_tree_node* x, int level)
{ /*<<<*/
/*
 * in order walk through binary tree
 * -> see book or slides
 */
  if (x != nullptr)
  {
    inorder_output(x->left, level+1);
    //cout << "(" << x->key << "," << level << ")" << endl;
    array[array_index] = x->key;
    array_index = array_index + 1;
    inorder_output(x->right, level+1); 
  }
} /*>>>*/

void bs_tree::remove_all(bs_tree_node* x)
{ /*<<<*/
/*
 * recursively remove all tree elements
 */
  if (x != nullptr)
    {
      remove_all(x->left);
      remove_all(x->right);

      delete x;
    }
} /*>>>*/


