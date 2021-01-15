#include <iostream>
#include <stdio.h>
using namespace std;

void bubbleSort(vector<int>& numsToSort) {
    int arraySize = numsToSort.size();
    for(int i = 0; i < arraySize; i++) {
        for(int j = 0; j < arraySize - i - 1; j++) {
            if(numsToSort[j] > numsToSort[j+1]) {
                int temp = numsToSort[j];
                numsToSort[j] = numsToSort[j+1];
                numsToSort[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> numsToSort;
    int input;
    for(int i = 0; i < n; i++) {
        cin >> input;
        numsToSort.push_back(input);
    }

    bubbleSort(numsToSort);
    for(int i = 0; i < numsToSort.size(); i++) {
        cout << numsToSort[i] << endl;
    }    
}