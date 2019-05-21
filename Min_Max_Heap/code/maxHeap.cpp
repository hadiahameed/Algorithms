#include <iostream>
#include <climits>
#include "maxHeap.h"

using namespace std; 

//maxHeap.cpp
maxHeap::maxHeap(int cap) 
{ 
	heapArray = new int [cap];
	heapSize = 0;
	capacity = cap;
} 

maxHeap::~maxHeap()
{
    delete heapArray;
}

void maxHeap::insertKey(int k) 
{ 
	if (capacity==0){
		cout<<"The total heap capacity is zero. "<<endl;
		return;
	}
	if(heapSize < capacity){
		*(heapArray + heapSize) = k;
		int i = heapSize;
		while(i!=0 && (k > *(heapArray + parent(i)))){
			int temp = *(heapArray + i);
			*(heapArray + i) = *(heapArray + parent(i));
			*(heapArray + parent(i)) = temp;
			i = parent(i);
		}

		heapSize = heapSize + 1;
	}
	else{
		cout<<"Heap is full."<<endl;
	}
} 

void maxHeap::increaseKey(int i, int new_val) 
{
	if (capacity==0){
		cout<<"The total heap capacity is zero. "<<endl;
		return;
	}
	if (heapSize == 0){
		cout<<"Heap underflow"<<endl;
		return;
	}
	if (i >= heapSize){
		cout<<"index i is out of bounds"<<endl;
		return;
	}
	if(new_val < *(heapArray + i))
		cout<<"New key is smaller than the current key."<<endl;
	else{
		*(heapArray + i) = new_val;
		while(i > 0 && *(heapArray + parent(i)) < *(heapArray + i)){
			int temp = *(heapArray+i);
			*(heapArray+i) = *(heapArray+parent(i));
			*(heapArray + parent(i)) = temp;
			i = parent(i);
		}
	}
} 

int maxHeap::extractMax() 
{
	if (capacity==0){
		cout<<"The total heap capacity is zero. "<<endl;
		return 0;
	}
	if(heapSize==0){
		cout<<"Heap underflow"<<endl;
		return 0;
	}
	else {
		int n = heapSize - 1;
		int max = *(heapArray);
		int * newData = new int[n];
		for ( int i = 0; i < n; i ++){
			if (i == 0)
				newData[i] = heapArray[n];
			else
				newData[i] = heapArray[i];
		}
		delete [] heapArray;
		heapArray = newData;
		heapSize = heapSize - 1;
		maxHeapify(0);
		return max; 
	}
} 
 
void maxHeap::deleteKey(int i) 
{ 
	if (capacity==0){
		cout<<"The total heap capacity is zero. "<<endl;
		return;
	}
	if (i >= heapSize)
		cout<<"Index exceeds heap size."<<endl;
	else {
		int n = heapSize;
		int index = i;
		while(i<n-1){
			*(heapArray+i) = *(heapArray+i+1);
			i = i + 1;
		}
		heapSize = heapSize - 1;
		maxHeapify(index);
    }
	

} 

void maxHeap::maxHeapify(int i) 
{ 
	if (i > heapSize){
		cout<<"Index i exceeds heap size."<<endl;
	}
	else {
		int* A = heapArray;
		int n = size();
		int l = left(i);
		int r = right(i);
		int largest = 0;
		if(l < n && *(A+l) > *(A+i))
			largest = l;
		else
			largest = i;
		if (r < n && *(A+r)>*(A+largest))
			largest = r;
		if (largest != i ){
			int temp = *(A+largest);
			*(A+largest) = *(A+i);
			*(A+i) = temp;
			maxHeapify(largest);
		}
	}
	
} 
