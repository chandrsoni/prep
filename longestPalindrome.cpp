class Solution {
    int sameSize(string s1, string s2) {
        for(int i = 0; i < min(s1.size(), s2.size()); i++) {
            if(s1[s1.size() - 1 - i] != s2[i]) {
                return i;
            }
        }
        
        return min(s1.size(), s2.size());
    }
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return s;
        int maxSize = 1;
        string maxSubstring = s.substr(0,1);
        for(int i = 0; i < s.size(); i++) {
            int sameLength = sameSize(s.substr(0, i), s.substr(i + 1));
            cout << i << "," << sameLength << endl;
            cout << s.substr(0, i) << "," << s.substr(i + 1) << endl;
            if(2 * sameLength + 1 > maxSize) {
                maxSize = 2 * sameLength + 1;
                maxSubstring = s.substr(i - sameLength, 2 * sameLength + 1);
            }
            sameLength = sameSize(s.substr(0, i + 1), s.substr(i + 1));
            cout << i << "," << sameLength << endl;
            cout << s.substr(0, i + 1) << "," << s.substr(i + 1) << endl;
            if(2 * sameLength > maxSize) {
                maxSize = 2 * sameLength;
                maxSubstring = s.substr(i + 1 - sameLength, 2 * sameLength);
            }
        }
        return maxSubstring;
    }
};
int main() {
    Solution sol;
    cout << sol.longestPalindrome("cbbd") << endl;
    std::cout << "Hello World!\n";
}