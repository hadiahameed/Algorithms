#ifndef __medianHeaps_h__
#define __medianHeaps_h__

#include "minHeap.h"
#include "maxHeap.h"

// A class for Median Heap
class medianHeaps
{ 
    // member variables
    maxHeap* maxH;
    minHeap* minH;
    int totalCapacity;
    /*maxHeap maxH = maxHeap();
    minHeap minH = minHeap();*/
    int medianHeapSize;
    
public: 
    // Constructor 
    medianHeaps(int capacity); 

    // Destructor
    ~medianHeaps();
  
    // Adds a new number and stores it in the two heaps to maintain the median value
    void addNewNumber(int x);
    
    // Returns median value from randomly generated values
    int getMedian();
};

#endif // __medianHeaps_h__