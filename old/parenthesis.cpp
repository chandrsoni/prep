class Solution {
public:
    map<int, vector<string>> parenthesisMemoize;
    vector<string> generateParenthesis(int n) {
        set<string> results;
        if(n == 0) return vector<string>();
        if(parenthesisMemoize.find(n) != parenthesisMemoize.end()) return parenthesisMemoize[n];
        vector<string> firstHalfResult;
        firstHalfResult.push_back("()");
        if(n == 1) {
            return firstHalfResult;
        }
        vector<string> secondHalfResult = generateParenthesis(n - 1);
        for(int k = 0; k < secondHalfResult.size(); k++) {
            results.insert('(' + secondHalfResult[k] + ')');
        }
        for(int i = 1; i < n; i++) {
            firstHalfResult = generateParenthesis(i);
            secondHalfResult = generateParenthesis(n - i);
            for(int j = 0; j < firstHalfResult.size(); j++) {
                for(int k = 0; k < secondHalfResult.size(); k++) {
                    results.insert(firstHalfResult[j]+secondHalfResult[k]);
                }
            }
        }
        vector<string> resultVector(results.begin(), results.end());
        
        parenthesisMemoize[n] = resultVector;
        return resultVector;
    }
};