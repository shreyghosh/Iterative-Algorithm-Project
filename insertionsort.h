#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <iostream>
#include <vector>

template <typename T>

// Function enabling bubblesort of a vector
std::vector<T> insertionSort(std::vector<T>& someVec)
{
    int swapCount{0};
    int compareCount{0};
    // initiates variable for storage
    int j;

    // For loop to loop over all indexes in list
   for(int i{1}; i < someVec.size() ; i++)
   {
       // Sets currVal to current value
       // Sets j to the current value index
      T currVal = someVec[i];
      j = i;
      compareCount++;

      // loops over all indexes between 0 and currVal - 1
      // While loop runs if the value before is greater than current
      while(j > 0 && someVec[j-1] > currVal)
      {
          compareCount++;
          // Switches current value with value before it
         someVec[j] = someVec[j-1];
        swapCount++;
         j--;
      }
      someVec[j] = currVal;   //insert in right place
   }
   cout << "Number of comparisons: " << compareCount << endl;
   cout << "Number of swaps: " << swapCount << endl;
   return someVec;
}

#endif // INSERTIONSORT_H
