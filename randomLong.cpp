class Solution {
    vector<unsigned long int> maxIntervalWeight;
public:
    Solution(vector<int>& w) {
        srand(time(NULL));
        unsigned long int currentTopWeight = 0;
        for(int i = 0; i < w.size(); i++) {
            currentTopWeight += w[i];
            maxIntervalWeight.push_back(currentTopWeight);
            cout << currentTopWeight << endl;
        }
    }
    
    int pickIndex() {
        unsigned long int firstComponent = (((unsigned long int)rand()) << 32);
        unsigned long int secondComponent = ((unsigned long int)rand());
        // cout << firstComponent << ", " << secondComponent << endl;
        unsigned long int randomGen = firstComponent + secondComponent;
        // cout << "randomGen "<< randomGen << endl;
        unsigned long int random = randomGen % maxIntervalWeight[maxIntervalWeight.size() - 1];
        // cout << " random " << ", " << random << endl;
        
        for(int i = 0; i < maxIntervalWeight.size(); i++) {
            if(maxIntervalWeight[i] > random) { return i;}
        }
        return maxIntervalWeight.size() - 1;
    }
};

int main () {
    vector<int> w{3, 14, 1, 7};
    Solution* obj = new Solution(w);
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << obj->pickIndex() << endl;
    cout << "hello world!" << endl;
}