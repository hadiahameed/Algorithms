#include <iostream>
#include <climits>
#include "medianHeaps.h"
#include "minHeap.h"
#include "maxHeap.h"

using namespace std; 

medianHeaps::medianHeaps(int cap) 
{
    maxH = new maxHeap(cap);
    minH = new minHeap(cap);
    totalCapacity = cap;
    medianHeapSize = 0;
    
	
} 

medianHeaps::~medianHeaps()
{
    delete maxH;
    delete minH;

}

void medianHeaps::addNewNumber(int x) 
{
    if (medianHeapSize <= totalCapacity){
        maxH->insertKey(x);
        minH->insertKey(x);
        medianHeapSize = medianHeapSize + 1;
    }
    else 
        cout<<"Cannot add more items."<<endl;
} 

 
int medianHeaps::getMedian() 
{
    int medianMinHeap =0;
    int medianMaxHeap =1;
    int median;
    if (medianHeapSize%2 == 0){
        int half = medianHeapSize/2;
        for(int i=0;i<half;i++){
           medianMinHeap = minH->extractMin();
           medianMaxHeap = maxH->extractMax(); 
        }
        median = (medianMinHeap+medianMaxHeap)/2;
    }
    else{
        while(medianMinHeap!=medianMaxHeap){
            medianMinHeap = minH->extractMin();
            medianMaxHeap = maxH->extractMax();
        }
        median = medianMinHeap;
    }
    return median;
} 
