class Solution {
    map<string, vector<string>> wordBreakMemo;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDict(begin(wordDict), end(wordDict));
        if(wordBreakMemo.find(s) != wordBreakMemo.end()) {
            return wordBreakMemo[s];
        }
        if(s == "") {
            return vector<string>(1, "");
        }
        
        string firstSubString = "";
        
        vector<string> result;
        
        for(int i = 0; i < s.size(); i++) {
            firstSubString += s[i];
            if(wordDict.find(firstSubString) != wordDict.end()) {
                vector<string> laterSubstringList = wordBreak(s.substr(i+1), wordDict);
                for(int j = 0; j < laterSubstringList.size(); j++) {
                    laterSubstringList[j] = firstSubString + " " + laterSubstringList[j];
                    result.push_back(laterSubstringList[j]);
                }
            }
        }
        
        wordBreakMemo[s] = result;
        return result;
    }
};