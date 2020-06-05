map<string, map<string, string>> lcsMemo;

string longestSubstring(string s1, string s2) {
    if(s1 == "" || s2 == "") {
        return "";
    }
    if(s1.size() > s2.size()) {
        swap(s1, s2);
    }
    if(lcsMemo.find(s1) != lcsMemo.end()) {
        if(lcsMemo[s1].find(s2) != lcsMemo[s1].end()) {
            return lcsMemo[s1][s2];
        }
    }
    string maxLengthString = "";
    if(s1[0] == s2[0]){
        maxLengthString = s1[0] + longestSubstring(s1.substr(1), s2.substr(1));
    } else {
        string s1Disable = longestSubstring(s1.substr(1), s2);
        string s2Disable = longestSubstring(s1, s2.substr(1));
        maxLengthString = s1Disable.size() > s2Disable.size() ? s1Disable : s2Disable;
    }
    
    if(lcsMemo.find(s1) == lcsMemo.end()) {
        lcsMemo[s1] = map<string, string>();
    }
    lcsMemo[s1][s2] = maxLengthString;
    
    return maxLengthString;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << longestSubstring(s1, s2) << endl;
    std::cout << "Hello World!\n";
}