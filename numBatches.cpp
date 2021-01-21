int getNumBatches(vector<int> cups, int nCups, int current) {
    if(current == nCups) {
        return 1 + getNumBatches(cups, nCups, 0);
    }
    
    int result = 0;
    bool hasMore = false;
    for(int i = 0; i < cups.size() ; i++) {
        if(cups[i] != 0) {
            hasMore = true;
            vector<int> newCups(cups);
            newCups[i]--;
            result = max(result, getNumBatches(newCups, nCups, current + i + 1));
        }
    }
    
    if(!hasMore) {
        return 1;
    }
    return result;
}

int freshBatches(int nCups, vector<int> batches) {
    vector<int> extraCups(nCups - 1, 0);
    int totalResult = 0;
    for(int i = 0; i < batches.size(); i++) {
        int rem = batches[i] % nCups;
        if(rem == 0) {
            totalResult++;
            continue;
        }
        if(extraCups[nCups - rem-1] > 0) {
            extraCups[nCups - rem -1] --;
            totalResult++;
            continue;
        }
        extraCups[batches[i] %nCups - 1]++;
    }
    
    return totalResult + getNumBatches(extraCups, nCups, 0);
}

int main() {
    int nCup = 3;
    vector<int> batches{3,4};
    cout << freshBatches(nCup, batches) << endl;
    std::cout << "Hello World!\n";
}