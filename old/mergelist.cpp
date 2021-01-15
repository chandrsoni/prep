
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int index1 = m - 1, index2 = n - 1;
    while(index1 >= 0 && index2 >= 0) {
        if(nums1[index1] > nums2[index2]) {
            nums1[index1 + index2 + 1] = nums1[index1];
            index1--;
        } else {
            nums1[index1 + index2 + 1] = nums2[index2];
            index2--;
        }
    }
    while(index2 >= 0) {
        nums1[index2] = nums2[index2];
        index2--;
    }
}

int main() {
    vector<int> nums1(6, 0), nums2(3, 0);
    nums1[0] = 1;
    nums1[1] = 2;
    nums1[2] = 3;
    nums2[0] = 2;
    nums2[1] = 5;
    nums2[2] = 6;
    merge(nums1, 3, nums2, 3);
    for(int i = 0; i < 6; i++) {
        cout << nums1[i] << endl;
    }
    std::cout << "Hello World!\n";
}