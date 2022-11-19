#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
#include <vector>

template <typename T>

// Function to swap 2 numbers
void swap2(T Num1, T Num2, std::vector<T>& someVec, int curPos, int minPos)
{
    someVec[curPos] = Num2;
    someVec[minPos] = Num1;
}

template <typename T>

// Function enabling bubblesort of a vector
std::vector<T> selectionSort(std::vector<T>& someVec)
{
    int swapCount{0};
    int compareCount{0};
    // Stores minimum value
    int minVal;

    // iterates over the list, setting the minimum value to the current value
    // Checks if any values in front are smaller
    // sets smallest value in front to minval
    for (int i{0}; i < someVec.size()-1; i++)
    {
        minVal = i;

        for (int j=i+1; j < someVec.size(); j++)
        {
            compareCount++;
            if (someVec[j] < someVec[minVal])
                minVal = j;
        }

        // If the minimum value isnt the current value
        // Switches the minimum value in list with current value
        // Min val in list is now to the front
        if (minVal != i)
        {

            T Num1 = someVec[i];
            T Num2 = someVec[minVal];

            swap2(Num1, Num2, someVec, i, minVal);
            swapCount++;
        }
    }
    cout << "Number of comparisons: " << compareCount << endl;
    cout << "Number of swaps: " << swapCount << endl;
    return someVec;
}

#endif // SELECTIONSORT_H
