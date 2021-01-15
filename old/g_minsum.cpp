int main () {
    int n;
    cin >> n;
    vector<int> nums;
    int input;
    for(int i = 0; i < n; i++) {
        cin >> input;
        nums.push_back(input);
    }
    
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++) {
        cout << nums[i] <<", ";
    }
    cout << endl;
    
    int minSum = nums[n-1] - nums[0];
    for(int i = 0; i <= 3; i++) {
        int sum = nums[(n-4 + i >= 0) 
                       ? n-4 + i
                       : 0]
             nums[i < n 
                  ? i 
                  : n - 1];
        if(minSum > sum) { minSum = sum;}
    }
    cout << minSum << endl;
}