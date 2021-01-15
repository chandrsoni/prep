#include <iostream>
#include <stdio.h>
using namespace std;

void quickSort(vector<int>& numsToSort, int begin, int end) {
    if(end - begin < 2){ return;}
    int comparator = numsToSort[begin];
    int leftIndex = begin;
    int lastSortedIndex = begin;
    for(int i = begin+1; i < end; i++) {
        if(numsToSort[i] < comparator) {
            int temp = numsToSort[i];
            numsToSort[i] = numsToSort[leftIndex];
            numsToSort[leftIndex] = temp;
            lastSortedIndex = i;
            leftIndex++;
        }
    }
    int temp = numsToSort[leftIndex];
    numsToSort[leftIndex] = numsToSort[lastSortedIndex];
    numsToSort[lastSortedIndex] = temp;
    for(int i = 0; i < numsToSort.size(); i++) {
        cout << numsToSort[i] << " ";
    }
    cout << endl;
    quickSort(numsToSort, begin, leftIndex);
    quickSort(numsToSort, leftIndex+ 1, end);
}

int main () {
    int n;
    cin >> n;
    vector<int> numsToSort;
    int input;
    for(int i = 0; i < n; i++) {
        cin >> input;
        numsToSort.push_back(input);
    }

    quickSort(numsToSort, 0, n);
    for(int i = 0; i < numsToSort.size(); i++) {
        cout << numsToSort[i] << endl;
    }    
}