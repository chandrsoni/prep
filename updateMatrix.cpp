bool isValid(int i, int j, int m, int n) {
    return i >=0 && j >= 0 && i < m && j <n;
}
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    if(matrix.size() == 0) return matrix;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> result(m, vector<int>(n, -1));
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) result[i][j] = 0;
        }
    }

    bool assigned = true;
    int currentValue = 0;
    while (assigned) {
        assigned = false;
        currentValue++;
        matrix = result;
        for(int i =0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] >= 0) continue;
                if((isValid(i-1, j, m,n) && matrix[i-1][j] != -1)
                  ||(isValid(i+1, j, m,n) && matrix[i+1][j] != -1)
                  ||(isValid(i, j-1, m,n) && matrix[i][j-1] != -1)
                  ||(isValid(i, j+1, m,n) && matrix[i][j+1] != -1)){
                    assigned = true;
                    result[i][j] = currentValue;
                }
            }
        }
    }

    return result;
}

int main() {
    int m,n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n,0));
    for(int i =0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    for(int i =0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    vector<vector<int>> result = updateMatrix(matrix);
    for(int i =0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}