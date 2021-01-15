#include <stdio.h>
#include <iostream>
using namespace std;

void insertionSort(vector<int>& numsToSort) {
    for(int i = 0; i < numsToSort.size(); i++) {
        vector<int>::iterator maxElm = min_element(numsToSort.begin() + i, numsToSort.end());
        cout << i << "  " << (*maxElm) << endl;
        int temp = *maxElm;
        cout << temp << "  " << (*maxElm) << " " << numsToSort[i] << endl;
        *maxElm = numsToSort[i];
        numsToSort[i] = temp;
        cout << temp << "  " << (*maxElm) << " " << numsToSort[i] << endl;
    }
    
    for(int i = 0; i < numsToSort.size(); i++ ) {
        cout << numsToSort[i] << endl;
    }
}

int main() {
    int count;
    cin >> count;
    vector<int> numsToSort;
    int input;
    for(int i = 0; i < count; i++) {
        cin >> input;
        numsToSort.push_back(input);
    }
    for(int i = 0; i < count; i++ ) {
        cout << numsToSort[i] << endl;
    }
    
    insertionSort(numsToSort);
    for(int i = 0; i < count; i++ ) {
        cout << numsToSort[i] << endl;
    }
    cout << "hello" << endl;
}
