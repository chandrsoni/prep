void bubbleDown(vector<int>& heapVec, int index) {
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    int isLeftSmaller = leftIndex < heapVec.size() && heapVec[leftIndex] < heapVec[index];
    int isRightSmaller = rightIndex < heapVec.size() && heapVec[rightIndex] < heapVec[index];
    if(isLeftSmaller && isRightSmaller) {
            if(heapVec[leftIndex] < heapVec[rightIndex]) {
                swap(heapVec[index], heapVec[leftIndex]);
                bubbleDown(heapVec, leftIndex);
            }
            else {
                swap(heapVec[index], heapVec[rightIndex]);
                bubbleDown(heapVec, rightIndex);
            }
            return;
        }
        if(isLeftSmaller) {
            swap(heapVec[index], heapVec[leftIndex]);
            bubbleDown(heapVec, leftIndex);
            return;
        }

        if(isRightSmaller) {
            swap(heapVec[index], heapVec[rightIndex]);
            bubbleDown(heapVec, rightIndex);
        }
}

void bubbleUp(vector<int>& heapVec, int index) {
    if(index == 0){return;}
    int parent = (index - 1) / 2;
    if(heapVec[index] < heapVec[parent]) {
        swap(heapVec[index], heapVec[parent]);
        bubbleUp(heapVec, parent);
    }
}

class defHeap {
    public:
    vector<int> intHeap;
    void insertNum(int value) {
        intHeap.push_back(value);
        bubbleUp(intHeap, intHeap.size() - 1);
    }
    bool isEmpty() {
        return intHeap.size() == 0;
    }
    int popNum() {
        int returnVal = intHeap[0];
        swap(intHeap[0], intHeap.back());
        intHeap.pop_back();
        bubbleDown(intHeap, 0);
        return returnVal;
    }
};

int main () {
    int n;
    cin >> n;
    defHeap numsToSort;
    int input;
    for(int i = 0; i < n; i++) {
        cin >> input;
        numsToSort.insertNum(input);
    }

    for(int i = 0; i < numsToSort.intHeap.size(); i++) {
        cout << numsToSort.intHeap[i] << endl;
    }
    numsToSort.insertNum(1);
    for(int i = 0; i < numsToSort.intHeap.size(); i++) {
        cout << numsToSort.intHeap[i] << endl;
    }
    
    while(!numsToSort.isEmpty()) {
        cout << numsToSort.popNum() << endl;
    }
}