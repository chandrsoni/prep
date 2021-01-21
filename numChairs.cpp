int maxChairs(vector<int> start, vector<int> end) {
    vector<int> merged(start);
    merged.insert(merged.end(), end.begin(), end.end());
    sort(merged.begin(), merged.end());
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    
    int currentChairs = 0, maxChairs = 0;
    int currentBegin = 0, currentEnd = 0;
    for(int i = 0; i < merged.size(); i++) {
        while(currentBegin < start.size() && start[currentBegin] <= merged[i]){
            currentBegin++;
            currentChairs++;
        }
        while(currentEnd < end.size() && end[currentEnd] <= merged[i]){
            currentEnd++;
            currentChairs--;
        }
        maxChairs = max(maxChairs, currentChairs);
    }
    
    return maxChairs;
}

int main() {
    vector<int> start{1, 2, 6, 5, 3}, end{5, 5, 7, 6, 8};
    
    
    cout << maxChairs(start, end) << endl;
    std::cout << "Hello World!\n";
}