#ifndef __BS_TREE_H__
#define __BS_TREE_H__

struct bs_tree_node 
{
  int		key;
  bs_tree_node*	left;
  bs_tree_node*	right;
  bs_tree_node*	p;
};

class bs_tree
{ 
  protected:
    bs_tree_node*	T_root;

  public:
    bs_tree();
    ~bs_tree();
    void insert(int*, int);
    void insert(int);
    int* inorder_output(int);
    /*void output()
      { output(T_root, 1); }*/
    int get_counter_duplicate() {
      return counter_duplicate;
    }

  protected:
    void insert(bs_tree_node*);
    void remove_all(bs_tree_node*);
    void inorder_output(bs_tree_node*, int);
    int* array;
    int array_index;
    int counter_duplicate;
};


#endif
