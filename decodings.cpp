
int numDecodings(string s) {
    if(s.size() == 0) return 0;
    if(stoi(s.substr(0,1)) == 0) return 0;
    if(s.size() == 1) return 1;
    if(s.size() == 2){
        return (stoi(s.substr(1,1)) != 0) + (stoi(s.substr(0, 2)) <= 26);
    }
    int result = numDecodings(s.substr(1));
    // cout << stoi(s.substr(0,2)) << endl;
    if(stoi(s.substr(0, 2)) <= 26) result += numDecodings(s.substr(2));
    return result;
}

int main () {
    string s = "812";
    cout << numDecodings("10") << endl;
}