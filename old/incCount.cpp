
int count(vector<int>& a, vector<vector<int>>& higherIndex, int i, int k, vector<vector<int>>& memoizeCount) {
    if(k < 0) { return 0;}
    if(k == 0) {return 1;}
    if(memoizeCount[i][k] != -1){ return memoizeCount[i][k];}
    int result = 0;
    for(int it = 0; it < higherIndex[i].size(); it++) {
        result += count(a, higherIndex, higherIndex[i][it], k -1, memoizeCount);
    }
    
    memoizeCount[i][k] = result;
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    int input;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> input;
        a[i] = input;
    }
    vector<vector<int>> memoizeCount(n, vector<int>(k,-1));
    vector<vector<int>> higherIndex(n, vector<int>());
    for(int i = 0; i < n; i ++) {
        for (int j = i+ 1; j < n; j++) {
            if(a[i] < a[j]) {
                higherIndex[i].push_back(j);
            }
        }
    }
    int result = 0;
    for(int i = 0; i < n; i++) {
        result += count(a, higherIndex, i , k - 1, memoizeCount);
    }
    std::cout << result << endl;
    std::cout << "Hello World!\n";
}