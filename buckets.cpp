
int getBucketCount(vector<int>& bucket) {
    int count = 0;
    for(auto it = 0; it < bucket.size(); it++) {
        count += bucket[it];
    }
    
    return count;
}

vector<vector<int>> buckets(int cap, vector<int>& weights, int currentIndex, vector<vector<int>>& bucketSet) {
    if(weights.size() <= currentIndex) {
        return bucketSet;
    }
    if(weights[currentIndex] > cap) {
        cerr << "cap too low" << endl;
        throw 2;
        return vector<vector<int>>();
    }
    int minSize = weights.size() + 1;
    vector<vector<int>> minBucketIt;
    for(auto ite = 0; ite < bucketSet.size(); ite++) {
        if(getBucketCount(bucketSet[ite]) + weights[currentIndex] < cap) {
            bucketSet[ite].push_back(weights[currentIndex]);
            auto addToBucket = buckets(cap, weights, currentIndex + 1, bucketSet);
            if(addToBucket.size() < minSize) {
                minSize = addToBucket.size();
                minBucketIt = addToBucket;
            }
            bucketSet[ite].erase(bucketSet[ite].begin() + bucketSet[ite].size() - 1);
        }
    }
    
    bucketSet.push_back(vector<int>({weights[currentIndex]}));
    auto addToBucket = buckets(cap, weights, currentIndex + 1, bucketSet);
    if(addToBucket.size() < minSize) {
        minSize = addToBucket.size();
        minBucketIt = addToBucket;
    }
    bucketSet.erase(bucketSet.begin() + bucketSet.size() - 1);
    
    return minBucketIt;
}

int main() {
    int cap = 20;
    vector<int> weights{10,10,5,5,5,4,4,4};
    vector<vector<int>> temp, bucket = buckets(cap, weights, 0, temp);
    for(int i = 0; i < bucket.size(); i++) {
        for(int j = 0; j < bucket[i].size(); j++) {
            cout << bucket[i][j] << ", ";
        }
        cout << endl;
    }
    std::cout << "Hello World!\n";
}