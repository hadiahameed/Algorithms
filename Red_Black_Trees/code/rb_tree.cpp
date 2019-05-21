
#include "rb_tree.h"
#include <list>
#include <iostream>
#include <cmath>

using namespace std;

/*
 * constructor/destructor
 */
rb_tree::rb_tree()
{ /*<<<*/
/*
 * create T_nil element
 */
  T_nil = new rb_tree_node();
  T_nil->color = RB_BLACK;
  T_nil->p = T_nil;
  T_nil->left = T_nil;
  T_nil->right = T_nil;
  counter_right_rotate = 0;
  counter_left_rotate = 0;
  counter_duplicate = 0;
  counter_case1 = 0;
  counter_case2 = 0;
  counter_case3 = 0;
  array = new int[1];

/*
 * root of rb tree
 */
  T_root = T_nil;
} /*>>>*/

rb_tree::~rb_tree()
{ /*<<<*/ 
/*
 * delete nil element and all other allocated nodes
 */
  remove_all(T_root);

  delete T_nil;
  delete[] array;
} /*>>>*/

void rb_tree::insert(int* key_array, int n)
{ /*<<<*/
  for (int i = 0; i < n; i++)
    insert(key_array[i]);
} /*>>>*/

void rb_tree::insert(int key)
{ /*<<<*/
/*
 * wrapper around insert
 * -> creates black node with key
 * -> inserts node
 */
  rb_tree_node* z;

  z = new rb_tree_node;
  z->color = RB_BLACK;
  z->key = key;

  insert(z);
} /*>>>*/

void rb_tree::insert(rb_tree_node* z)
{ /*<<<*/
/*
 * binary tree type insert 
 * -> search position, insert new node
 * -> fix properties after insert
 */
  rb_tree_node* x;
  rb_tree_node* y;

  y = T_nil;
  x = T_root;
  while (x != T_nil)
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
  if (y == T_nil)
    T_root = z;
  else
  {
    if (z->key < y->key)
	    y->left = z;
    else
	    y->right = z;
  }

  z->left = T_nil;
  z->right = T_nil;
  z->color = RB_RED;

/*
 * after binary tree type insert we need to fix RB tree properties
 * -> update the info file
 */
  insert_fixup(z);
} /*>>>*/

void rb_tree::insert_fixup(rb_tree_node*& z)
{ /*<<<*/
/*
 * fix RB tree properties, after inserting a node
 * -> see book/slides for details on the cases
 */
  rb_tree_node* y;

  while (z->p->color == RB_RED)
  {
    if (z->p == z->p->p->left)
	  {
	    y = z->p->p->right;

	    if (y->color == RB_RED)
	    {
        counter_case1 = counter_case1 + 1;
        z->p->color = RB_BLACK;		// Case 1
        y->color = RB_BLACK;
        z->p->p->color = RB_RED;
        z = z->p->p;
	    }
	    else
	    {
	      if (z == z->p->right)
		    {
          counter_case2 = counter_case2 + 1;
		      z = z->p;			// Case 2
		      left_rotate(z);
          counter_left_rotate = counter_left_rotate + 1;
		    }
        counter_case3 = counter_case3 + 1;
	      z->p->color = RB_BLACK;		// Case 3
	      z->p->p->color = RB_RED;
	      right_rotate(z->p->p);
        counter_right_rotate = counter_right_rotate + 1;
	    }
	  }
    else
	  {
      y = z->p->p->left;
      if (y->color == RB_RED)
	    {
        counter_case1 = counter_case1 + 1;
	      z->p->color = RB_BLACK;		// Case 1
	      y->color = RB_BLACK;
	      z->p->p->color = RB_RED;
	      z = z->p->p;
	    }
	    else
	    {
	      if (z == z->p->left)
		    {
          counter_case2 = counter_case2 + 1;
		      z = z->p;			// Case 2
		      right_rotate(z);
          counter_right_rotate = counter_right_rotate + 1;
		    }
        counter_case3 = counter_case3 + 1;
	      z->p->color = RB_BLACK;		// Case 3
	      z->p->p->color = RB_RED;
	      left_rotate(z->p->p);
        counter_left_rotate = counter_left_rotate + 1;
	    }
	  }
  }

  T_root->color = RB_BLACK;
} /*>>>*/


void rb_tree::left_rotate(rb_tree_node* x)
{ /*<<<*/
/*
 * rotate left -> see book/slides
 */
  rb_tree_node* y;

  y = x->right;			// set y
  x->right = y->left;		// turn y's left subtree into x's right subtree
  if (y->left != T_nil)
    y->left->p = x;

  y->p = x->p;			// link x's parent to y
  if (x->p == T_nil)
    T_root = y;
  else
    {
      if (x == x->p->left)
	x->p->left = y;
      else
	x->p->right = y;
    }

  y->left = x;			// put x on y's left
  x->p = y;
} /*>>>*/

void rb_tree::right_rotate(rb_tree_node* x)
{ /*<<<*/
/*
 * rotate right -> see book/slides
 */
  rb_tree_node* y;

  y = x->left;			// set y
  x->left = y->right;		// turn y's right subtree into x's left subtree
  if (y->right != T_nil)
    y->right->p = x;

  y->p = x->p;			// link x's parent to y
  if (x->p == T_nil)
    T_root = y;
  else
    {
      if (x == x->p->right)
	x->p->right = y;
      else
	x->p->left = y;
    }

  y->right = x;			// put x on y's right
  x->p = y;
} /*>>>*/

int* rb_tree::inorder_output(int n) {
  if(array){
    delete[] array;
  }
  array = new int[n];
  array_index = 0;
  inorder_output(T_root, 1);
  return array;
}

void rb_tree::inorder_output(rb_tree_node* x, int level)
{ /*<<<*/
/*
 * in order walk through binary tree
 * -> see book or slides
 */
  if (x != T_nil)
    {
      inorder_output(x->left, level+1);
      /*cout << "(" << x->key << "," << level << "," 
	   << ((x->color == RB_RED) ? "R" : "B") << ")" << endl;*/
      array[array_index] = x->key;
      array_index = array_index + 1;
      inorder_output(x->right, level+1); 
    }
} /*>>>*/

/*void rb_tree::output(rb_tree_node* x, int r_level)
{
  list< pair<rb_tree_node*,int> > l_nodes;
  pair<rb_tree_node*,int> c_node;
  int c_level;

  c_level = r_level;
  l_nodes.insert(l_nodes.end(), pair<rb_tree_node*,int>(x, r_level));

  while (!l_nodes.empty())
    {
      c_node = *(l_nodes.begin());

      if (c_level < c_node.second)
	{
	  cout << endl;
	  c_level = c_node.second;
	}

      cout << "(" << c_node.first->key << "," 
	   << ((c_node.first->color == RB_RED) ? "R" : "B");

      if (c_node.first->p == T_nil)
	cout << ",ROOT) ";
      else
        cout << ",P:" << c_node.first->p->key << ") ";

      if (c_node.first->left != T_nil)
	l_nodes.insert(l_nodes.end(), pair<rb_tree_node*,int>(c_node.first->left, 
							      c_node.second+1));
      if (c_node.first->right != T_nil)
	l_nodes.insert(l_nodes.end(), pair<rb_tree_node*,int>(c_node.first->right, 
							      c_node.second+1));
      l_nodes.erase(l_nodes.begin());
    }

  cout << endl;
}*/

int rb_tree::rb_tree_height(rb_tree_node* x){
  if (x == T_nil) {
    return 0;
  }
  else
  {
    return max(rb_tree_height(x->left),rb_tree_height(x->right)) + 1;
  }
}

int max(int a, int b){
  if (a>=b){
    return a;
  }
  else {
    return b;
  }
}

void rb_tree::remove_all(rb_tree_node* x)
{ /*<<<*/
/*
 * recursively remove all tree elements
 */
  if (x != T_nil)
    {
      remove_all(x->left);
      remove_all(x->right);

      delete x;
    }
} /*>>>*/

