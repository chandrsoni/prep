#include <iostream>

void insertionSort(vector<int>& numsToSort) {

    for(int i = 0; i < numsToSort.size(); i++) {
        int minIndex = i;
        for(int j = i; j < numsToSort.size();j++) {
            if(numsToSort[j] < numsToSort[minIndex]) {
                minIndex = j;
            }
        }

        // can also use swap as swap(numsToSort[i], numsToSort[minIndex]);
        int minValue = numsToSort[minIndex];
        numsToSort[minIndex] = numsToSort[i];
        numsToSort[i] = minValue;
    }
}

int main() {
    vector<int> numsToSort{3,1,2,5,4};
    
    insertionSort(numsToSort);
    
    for( int i = 0 ; i < numsToSort.size(); i++) {
        cout << numsToSort[i] << endl;
    }
}