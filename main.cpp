#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "mergesort.h"
#include "bubblesort.h"
#include "insertionsort.h"
#include "selectionsort.h"

using namespace std;


// Function for input of file + running and timing of algorithm
void inputFile(string fileName, int alg)
{
    // File input
    ifstream inputFile("/Users/shreyghosh/Desktop/School Files/Grade 11 Files/Programming 25 C++/CSE 3110 Iterative Algorithm - I/Assignments/" + fileName + ".txt", ios::in);
    if(!inputFile)
    {
        cerr << "Unable to Open Input File \""+ fileName + "\" \nExiting. . .\n";
        //return 1;
    }

    // Output file creation
    ofstream outputFile(fileName + "_output.txt", ios::out | ios::trunc);
    if(!outputFile)
    {
        cerr << "Unable to Open or Create Output File \"90_percent_sorted_100_values_output.txt\"\nExiting. . .\n";
        //return 1;
    }

    // Input file .txt vector creation
    vector<int> numbers;
    int currentNum;
    while(true)
    {
        inputFile >> currentNum;
        if(inputFile.good())
            numbers.push_back(currentNum);
        else
            break;
    }

    // Starts clock for timing of algorithm
    auto start = chrono::steady_clock::now();
    // Switch statement to activate different alogrithms
    switch(alg)
    {
    case 1:
        bubbleSort(numbers);
        break;

    case 2:
        insertionSort(numbers);
        break;

    case 3:
        selectionSort(numbers);
        break;

    case 4:
        mergeSort(numbers);
        break;
    }
    // Ends timer for algorithm + calculates time taken
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;

    // output sorted numbers into sortedNumbers.txt
    for(int number : numbers)
        outputFile << number << '\n';
    cout << "Elapsed Time: " << elapsed_seconds.count() << "s" << endl;
}


int main()
{
    // Variable storage for desired algorithm and file
    int algNum;
    string userFile;

    // Menu option for algoritm choice and value
    cout << "Please make your choice of Algorithm: " << endl;
    cout << "1) Bubble Sort" << endl;
    cout << "2) Insertion Sort" << endl;
    cout << "3) Selection Sort " << endl;
    cout << "4) Merge Sort " << endl;

    // User enters choice of algorithm
    cout << "Please enter your choice of algorithm (1,2,3,4): ";
    cin >> algNum;

    // User enters choice of file
    cout << "Please enter your choice of file name: ";
    cin >> userFile;

    // Runs inputFile function
    inputFile(userFile, algNum);

    return 0;
}
