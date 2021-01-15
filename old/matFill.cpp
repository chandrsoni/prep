
int main () {
    int m,n;
    cin >> m >> n;
    string startPos;
    string strDirection;
    cin >> startPos >> strDirection;
    vector<vector<int>> matrix(m, vector<int>(n));
    int currentIndex = 1;
    bool hInc;
    bool vInc;
    int x, y;
    if(startPos[1] == 'L') {
        y = 0;
        hInc = true;
    } else {
        y = n - 1;
        hInc = false;
    }
    if(startPos[0] == 'T') {
        x = 0;
        vInc = true;
    } else {
        x = m - 1;
        vInc = false;
    }
    // traversal
    if(strDirection == "H") {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                matrix[x][y] = currentIndex++;
                if(hInc){y++;} else {y--;}
            }
            if(hInc) { y--;} else {y++;}
            if(vInc) {x++;} else {x--;}
            hInc = !hInc;
        }
    } else {
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                matrix[x][y] = currentIndex++;
                if(vInc){x++;} else {x--;}
            }
                if(vInc){x--;} else {x++;}
            if(hInc){y++;} else {y--;}
            vInc = !vInc;
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "hello world!" << endl;
}