int getExcludedNumber(int nums[], int k, int begin, int size) {
    if(begin >= size || nums[begin] > k) {return k;}
    return getExcludedNumber(nums, k+1, begin+1, size);
}

int main() {
    int n;
    cin >> n;
    int nums[n], k;
    
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;
    sort(nums, nums+n);
    // for(int i = 0; i < n; i++) {
        cout << getExcludedNumber(nums, k, 0, n) << endl;
    // }
    
    std::cout << "Hello World!\n";
}