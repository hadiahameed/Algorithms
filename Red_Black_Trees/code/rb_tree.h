#ifndef __RB_TREE_H__
#define __RB_TREE_H__
#include <cmath>

//enum is user-defined data type that consists of integral constants
enum rb_tree_color 
{
  RB_RED,
  RB_BLACK
};

struct rb_tree_node 
{
  int		key;
  int		color;
  rb_tree_node*	left;
  rb_tree_node*	right;
  rb_tree_node*	p;
};

class rb_tree
{ 
  protected:
    rb_tree_node*	T_nil;
    rb_tree_node*	T_root;

  public:
    rb_tree();
    ~rb_tree();

    void insert(int*, int);
    void insert(int);
    int* inorder_output(int);
    /*void output()
      { output(T_root, 1); }*/

    int get_counter_duplicate() {
      return counter_duplicate;
    }
    int get_counter_right_rotate() {
      return counter_right_rotate;
    }
    int get_counter_left_rotate() {
      return counter_left_rotate;
    }
    int get_counter_case1() {
      return counter_case1;
    }
    int get_counter_case2() {
      return counter_case2;
    }
    int get_counter_case3() {
      return counter_case3;
    }
   int rb_tree_test_function(){
     int black_height = rb_tree_height(T_root);
     return ceil(black_height/2); 
   };

  protected:
    void insert(rb_tree_node*);
    void insert_fixup(rb_tree_node*&);

    void remove_all(rb_tree_node*);

    void left_rotate(rb_tree_node*);
    void right_rotate(rb_tree_node*);
    

    void inorder_output(rb_tree_node*, int);
    void output(rb_tree_node*, int);
    int* array;
    int array_index;
    int counter_duplicate;
    int counter_right_rotate;
    int counter_left_rotate;
    int counter_case1;
    int counter_case2;
    int counter_case3;
    int rb_tree_height(rb_tree_node*);
    
};


#endif
