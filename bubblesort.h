#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include <iostream>
#include <vector>

template <typename T>

// Function to swap 2 numbers
void swap1(T Num1, T Num2, std::vector<T>& someVec, int curPos)
{
    someVec[curPos] = Num2;
    someVec[curPos + 1] = Num1;
}

template <typename T>

// Function enabling bubblesort of a vector
std::vector<T> bubbleSort(std::vector<T>& someVec)
{

    int swapCount{0};
    int compareCount{0};
    // Loops for every number present in the vector
    for (int j {0}; j <= someVec.size(); j++)
    {
        // Loops for every index in the vector
        for (int i{0}; i < someVec.size() -1; i++)
        {
            compareCount++;
            // If the current number is greater than the one after it, swap them
            if(someVec[i] > someVec[i+1])
            {

                T Num1 = someVec[i];
                T Num2 = someVec[i + 1];

                swap1(Num1, Num2, someVec, i);
                swapCount++;

            }
        }
    }
    std::cout << "Number of comparisons: " << compareCount << std::endl;
    std::cout << "Number of swaps: " << swapCount << std::endl;
    return someVec;
}

#endif // BUBBLESORT_H
