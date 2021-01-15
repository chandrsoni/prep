#include <iostream>

vector<int> mergeSort(vector<int>& numsToSort, int startIndex, int endIndex) {
    if(startIndex == endIndex) {
        return vector<int>{numsToSort[startIndex]};
    }
    int midIndex = (startIndex + endIndex)/2;
    vector<int> lSort = mergeSort(numsToSort, startIndex, midIndex);
    vector<int> rSort = mergeSort(numsToSort, midIndex+1, endIndex);
    vector<int> merge;
    int lPointer = 0, rPointer = 0;
    for(int i = 0; i <= endIndex - startIndex; i++) {
        if(rPointer >= rSort.size()) {
            merge.push_back(lSort[lPointer++]);
            continue;
        }
        if(lPointer >= lSort.size() || lSort[lPointer] > rSort[rPointer] ) {
            merge.push_back(rSort[rPointer++]);
            continue;
        }

        merge.push_back(lSort[lPointer++]);
    }
    return merge;
}

int main() {
    vector<int> numsToSort{3,1,2,5,4,7,0};
    numsToSort = mergeSort(numsToSort, 0, numsToSort.size() - 1);   
    for( int i = 0 ; i < numsToSort.size(); i++) {
        cout << numsToSort[i] << endl;
    }
}