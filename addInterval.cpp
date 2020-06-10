class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int beginInterval = newInterval[0];
        int endInterval = newInterval[1];
        vector<vector<int>> result;
        for(int i = 0; i<intervals.size();i++){
            if(intervals[i][1] < newInterval[0] || intervals[i][0] > newInterval[1]) {
                result.push_back(intervals[i]);
                continue;
            }
            beginInterval = min(beginInterval, intervals[i][0]);
            endInterval = max(endInterval, intervals[i][1]);
        }
        bool isInserted = false;
        for(int i = 0; i < result.size(); i++) {
            if(result[i][0] > beginInterval) {
                result.insert(result.begin() + i, vector<int>{beginInterval, endInterval});
                isInserted = true;
                break;
            }
        }
        if(!isInserted) result.push_back(vector<int>{beginInterval, endInterval});
        return result;
    }
};