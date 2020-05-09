#include <iostream>
#include <stdio.h>
using namespace std;

void mergeSort(vector<int>& numsToSort, int beginIndex, int endIndex) {
    
    cout << beginIndex << ", " << endIndex << endl;
    if(endIndex - beginIndex <= 1) {
        return;
    }
    cout << "here " << endl;
    int midIndex = (beginIndex + endIndex) / 2;
    mergeSort(numsToSort, beginIndex, midIndex);
    mergeSort(numsToSort, midIndex, endIndex);
    vector<int> mergeArray;
    int leftIndex = beginIndex, rightIndex = midIndex;
    while(leftIndex < midIndex && rightIndex < endIndex) {
        mergeArray.push_back(numsToSort[leftIndex] < numsToSort[rightIndex]
        ? numsToSort[leftIndex++]
        : numsToSort[rightIndex++]);
    }
    while(leftIndex < midIndex) {
        mergeArray.push_back(numsToSort[leftIndex++]);
    }

    for(int i = 0; i < mergeArray.size(); i++) {
        numsToSort[i + beginIndex] = mergeArray[i];
    }
}

int main() {
    int count; 
    cin >> count;
    int input;
    vector<int> numsToSort;
    for(int i = 0; i < count; i++) {
        cin >> input;
        numsToSort.push_back(input);
    }

    mergeSort(numsToSort, 0, count);
    for(int i = 0; i < count; i++) {
        cout << numsToSort[i] << endl;
    }
}