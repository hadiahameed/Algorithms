#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
#include "LinkedList.h"

using namespace std;

//merge sort algorithm used from homework 1
void merge(vector<int>* v, int start_index, int q, int rows)
{ 
  vector<int> &vect = *v;
  int n1 = q - start_index + 1;
  int n2 = rows - q;

  int* L = new int[n1+1];
  int* R = new int[n2+1];
  for(int i = 0; i < n1; ++i){
    L[i] = vect[start_index + i];
  }
  for(int j = 0; j < n2; ++j){
    R[j] = vect[q + j + 1];
  }
  L[n1] = std::numeric_limits<int>::max();
  R[n2] = std::numeric_limits<int>::max();
  int i = 0;
  int j = 0;
  for (int k = start_index; k <= rows; k++) {
    if (L[i]<=R[j]) {
      vect[k] = L[i];
      i = i + 1;
    }
    else {
      vect[k] = R[j];
      j = j + 1;
    }
  }

  delete[] L;
  delete[] R; 
}

void merge_sort(vector<int> *vect, int start_index, int rows)
{ 
  int q;
	if (start_index < rows) //p<r
	{
		q = floor((start_index + rows) / 2);
		// Split the data into two half.
		merge_sort(vect, start_index, q);
		merge_sort(vect, q + 1, rows);

		// Merge them to get sorted output.
		merge(vect, start_index, q,rows);
	}
}

// First implementation; uses additional data structure
void removeDupl_1(Node* head)
{
  Node* temp;
  Node* duplicate_node;
  vector<int> vect;

  if (head == NULL)
  {
    cout<<"List is empty."<<endl;
    return;
  }

  temp = head;
    
  //copy elements from the list into the vector
  while (temp != NULL)
  {
    vect.push_back(temp->data);
    temp = temp->next;
  }

  //v is pointer to a vector
  vector<int> *v = &vect;
  int rows = vect.size()-1;

  //sorting the vector
  merge_sort(v, 0, rows);


  temp = head;
  int i = 0;

  /*copy elements from the sorted vector to the list and 
    removing any duplicates during the copying process*/
  while (temp != NULL)
  {    
    if(i<vect.size() && vect[i]==vect[i+1]){
      duplicate_node = temp->next;
      temp->next = temp->next->next;
      delete duplicate_node;
      i = i + 1;
    }
    else{
      temp->data = vect[i];
      temp = temp->next;
      i = i + 1;
    }
    if(i>vect.size()){
      temp = NULL;
    }
  }

}


// This implementation uses no additional data structure 
void removeDupl_2(Node* head)
{
  //Check if the list is empty
  if(head==NULL){
    cout<<"List is empty."<<endl;
    return;
  }
  Node* temp1;
  Node* temp2;
  Node* temp2_next;
  Node* duplicate;
  
  /*temp1 will be fixed in the outer while loop 
     and temp2 will move along the list in the inner while loop*/
  temp1 = head;
  while(temp1!=NULL&&temp1->next!=NULL){
    temp2 = temp1;
    while(temp2->next != NULL){
      temp2_next = temp2->next;
      int data1 = temp1->data;
      int data2 = temp2_next->data;

      if(data1==data2){
        duplicate = temp2_next;
        temp2->next = temp2_next->next;
        delete duplicate;
      }
      else{
        temp2 = temp2->next;
      }
  }
  temp1 = temp1->next;
  }    
}


int main()
{
  /*Using removeDup1:*/
    LinkedList* myList1 = new LinkedList();
    myList1->insert(5);
    myList1->insert(7);
    myList1->insert(12);
    myList1->insert(7);
    myList1->insert(16);
    myList1->insert(16);
    myList1->insert(25);
    myList1->insert(11);
    myList1->insert(5);

    cout << "The original list is: ";
    myList1->display();

    cout<<"Use removeDupl_1 to run that implementation:"<<endl;
    removeDupl_1(myList1->head);
    //If the list was not empty in the first place, display the returned list
    if(myList1->head!=NULL){
      cout << "The list with duplicated removed is: "<<endl;
      myList1->display();
    }
    delete myList1;

  /*Using removeDup2*/
    LinkedList* myList2 = new LinkedList();
    myList2->insert(5);
    myList2->insert(7);
    myList2->insert(12);
    myList2->insert(7);
    myList2->insert(16);
    myList2->insert(16);
    myList2->insert(25);
    myList2->insert(11);
    myList2->insert(5);
    cout << "The original list is: "<<endl;
    myList2->display();

    cout<<"Use removeDupl_2 to run that implementation:"<<endl;
    removeDupl_2(myList2->head);
    //If the list was not empty in the first place, display the returned list
    if(myList2->head!=NULL){
      cout << "The list with duplicated removed is: ";
      myList2->display();
    }
    delete myList2;

    return 0;
}