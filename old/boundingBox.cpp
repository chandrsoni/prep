
bool isStillInField(vector<vector<int>>& mineField, int xIndex) {
    // cout << xIndex << endl;
    for(int i = 0; i < mineField[xIndex].size(); i++) {
        if(mineField[xIndex][i] == 1){
            return true;
        }
    }
    
    return false;
}

bool isStillInFieldLower(vector<vector<int>>& mineField, int xIndex) {
    for(int i = 0; i < mineField[xIndex].size(); i++) {
        if(mineField[xIndex][i] == 1){
            return false;
        }
    }
    
    return true;
}
bool isStillInFieldy(vector<vector<int>>& mineField, int yIndex) {
    // cout << yIndex << endl;
    for(int i = 0; i < mineField.size(); i++) {
        if(mineField[i][yIndex] == 1){
            return true;
        }
    }
    
    return false;
}
bool isStillInFieldyLower(vector<vector<int>>& mineField, int yIndex) {
    cout << "lower"<<  yIndex << endl;
    for(int i = 0; i < mineField.size(); i++) {
        if(mineField[i][yIndex] == 1){
            return false;
        }
    }
    
    return true;
}

template <typename Predicate>
int findBoundaryIndex(vector<vector<int>>& minefield, int startIndex, int endIndex, Predicate fulfill) {
    cout << startIndex << ", " << endIndex << endl;
    if((endIndex - startIndex) < 2) {
        if(fulfill(minefield, startIndex)){return startIndex;}
        if(fulfill(minefield, endIndex)) {return endIndex;}
        throw;
    }
    
    int midIndex = (startIndex + endIndex)/2;
    if(fulfill(minefield, midIndex)){
        return findBoundaryIndex(minefield, startIndex, midIndex, fulfill);
    } else {
        return findBoundaryIndex(minefield, midIndex, endIndex, fulfill);
    }
}


int main () {
    int m, n;
    cin >> m >> n;
    int input;
    vector<vector<int>> minefield(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j <n; j++) {
            cin >> input;
            minefield[i][j] = input;
        }
    }
    int i, j;
    cin >> i >> j;
    
    cout << findBoundaryIndex(minefield, 0, i, isStillInField) << endl;
    cout << findBoundaryIndex(minefield, i, m - 1, isStillInFieldLower) - 1 << endl;
    cout << findBoundaryIndex(minefield, 0, j, isStillInFieldy) << endl;
    cout << findBoundaryIndex(minefield, j, n - 1, isStillInFieldyLower) - 1 << endl;
    cout << "hello world" << endl;
}