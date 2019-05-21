#include <iostream>
#include <vector>
#include <algorithm>
#include "medianHeaps.h"
#include "random_generator.h"

using namespace std;


// tests if the median estimated with the two heaps is the actual median value of 
// the randomly generated numbers
bool testMedian(vector<int> input, int medianValue)
{
    int vectorMedian = 0;
    size_t size = input.size();

    if (size == 0)
    {
        return 0;
    }
    else
    {
        sort(input.begin(), input.end());
        if (size % 2 == 0)
        {
            vectorMedian = (input[size/2 - 1] + input[size/2])/2;
        }
        else
        {
            vectorMedian = input[size/2];    
        }   
    }
    return (vectorMedian == medianValue);
}



int main(int argc, char* argv[])
{
    int m;
    random_generator rg;
    int newNumber = 0;
    vector<int> randNumbers;

    if (argc == 2)
    { 
      m = atoi(argv[1]);
      m = (m < 1) ? 1 : m;
    }
    else
    {
      cout << "hw3: [m]" << endl;
      cout << "[m]              number of the random numbers generated" << endl;
      cout << endl;
      return 0;
    }

    medianHeaps* medianH = new medianHeaps(m);
    
    // use heaps to store m random numbers to find and maintain the median value
    for (int i=0;i<m;++i)
    {
        rg >> newNumber;
        newNumber %= 100;
        // keep randomly generated numbers in an stl vector for testing
        randNumbers.push_back(newNumber);

        // store randomly generated numbers in the heaps
        medianH->addNewNumber(newNumber);
    }
    
    // testing
    if (testMedian(randNumbers, medianH->getMedian()))
    {
        cout << "The median was found, and maintained successfully!" << endl;
    }
    else
    {
        cout << "Wrong median value." << endl;
    }

    delete medianH;

    return 0;
}