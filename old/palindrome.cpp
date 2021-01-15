class Solution {
public:
    bool isPalindrome(string s) {
        string filteredString;
        for(int i = 0; i < s.size(); i++) {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
                filteredString.push_back(tolower(s[i]));
            }
        }
        
        int n = filteredString.size();
        for(int i = 0; i < n / 2; i++) {
            if(filteredString[i] != filteredString[n - i - 1]) return false;
        }
        
        return true;
    }
};