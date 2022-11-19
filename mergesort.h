#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * Merge two sorted regions within a vector
 *
 * @param list the vector with the values to be merged
 * @param left the starting index value of the first sorted region
 * @param middle the separating index value between the first and second sorted regions
 * @param right the last ending index value fo the second sorted region
 * @param reverse whether or not to sort the vector in descending order (default: false)
 */
template <typename T>
int merge(vector<T>& list, size_t& left, size_t& middle, size_t& right, bool reverse = false) {
  // create a temporary vector
  vector<T> mergedList;
  int comparecount{0};

  // left and right pointers for the current position within each sorted region
  size_t p1 = left, p2 = middle;

  // loop through the total size of the sorted region number of times
  for (size_t i = 0; i < right - left; i++) {
    // if either pointer has reached their maximum position, push an element of the other region to the merged list
    if (p1 == middle) {
      mergedList.push_back(list[p2++]);
      continue;
    }
    if (p2 == right) {
      mergedList.push_back(list[p1++]);
      continue;
    }
    comparecount++;
    // compare the value at each region's pointer and push to the merged list the appropriate value
    if (reverse ? list[p1] <= list[p2] : list[p1] >= list[p2]) {
        comparecount++;
      mergedList.push_back(list[p2++]);
    } else {
        comparecount++;
      mergedList.push_back(list[p1++]);
    }
  }

  // replace the contents of the vector with the temporary one
  for (size_t i = 0; i < mergedList.size(); i++) {
    list[left + i] = mergedList[i];
  }
  return comparecount;
}

/**
 * Merge sort iterative implementation
 *
 * @param list the vector to be sorted
 * @param reverse whether or not to sort the vector in descending order (default: false)
 */
template <typename T>
void mergeSort(vector<T>& list, bool reverse = false) {
    int compareNum{0};
  // start by sorting pairs of numbers, then double the sort size each time, until it is the size of the vector
  for (size_t currentSize = 2; currentSize <= list.size(); currentSize *= 2) {
    // loop through all sections of the current size
    for (size_t i = 0; i < list.size(); i += currentSize) {
      // calculate the starting, middle, and last index
      size_t left = i;
      size_t right = i + currentSize;
      size_t middle = left + (right - left) / 2;

      // if the number of elements is not a multiple of the current size,
      // merge the remainder region with the rest of the vector
      if (left + currentSize >= list.size()) {
        left = i - currentSize;
        right = list.size();
        middle = i;
      }

      // merge the selected region
      compareNum = merge(list, left, middle, right, reverse);
    }
  }
  cout << "Number of comparisons: " << compareNum << endl;
}


#endif // MERGESORT_H
