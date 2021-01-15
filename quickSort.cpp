#include <iostream>
using namespace std;

void quickSort(vector<int>& numsToSort, int startIndex, int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }

    int smallPointer = startIndex;
    for (int i = startIndex + 1; i <= endIndex; i++) {
        if (numsToSort[i] > numsToSort[startIndex]) {
            continue;
        }

        swap(numsToSort[++smallPointer], numsToSort[i]);
    }
    swap(numsToSort[smallPointer], numsToSort[startIndex]);

    quickSort(numsToSort, startIndex, smallPointer - 1);
    quickSort(numsToSort, smallPointer + 1, endIndex);
}

int main () {
    vector<int> numsToSort{3,1,2,5,4};
    quickSort(numsToSort, 0, numsToSort.size() - 1);
        for( int i = 0 ; i < numsToSort.size(); i++) {
        cout << numsToSort[i] << endl;
    }

}