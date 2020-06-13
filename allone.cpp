
class myexception: public exception
{
public:
    string errorMessage;
  virtual const char* what() const throw()
  {
    return &(errorMessage[0]);
  }
} myex;


class AllOne {
public:
    unordered_map<string, long long int> valMap;
    map<long long int, set<string>*> keyList;
    /** Initialize your data structure here. */
    AllOne() {
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        unordered_map<string, long long int>::iterator keyIt = valMap.find(key);
        if(keyIt == valMap.end()) {
            if(keyList.begin() -> first != 1) {
                keyList[1] = new set<string>(); 
            }
            keyList[1]->insert(key);
            valMap[key] = 1;
        } else {
            if(keyList[keyIt->second] == NULL) {
                myex.errorMessage = to_string(keyIt->second);
                throw myex;
            }
            keyList[keyIt->second]->erase(key);
            if(keyList[keyIt->second]->empty()) {
                delete keyList[keyIt->second];
                keyList.erase(keyIt->second);
            }
            keyIt->second++;
            if(keyList.find(keyIt->second) == keyList.end()) {
                keyList[keyIt->second] = new set<string>();
            }
            keyList[keyIt-> second]->insert(key);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        unordered_map<string, long long int>::iterator keyIt = valMap.find(key);
        if(keyIt == valMap.end()) {
            // error
            return;
        }
        keyList[keyIt->second]->erase(key);
        if(keyList[keyIt->second]->empty()) {
            delete keyList[keyIt->second];
            keyList.erase(keyIt->second);
        }
        keyIt->second--;
        if(keyIt -> second == 0) {
            valMap.erase(keyIt);
            return;
        }
        if(keyList.find(keyIt->second) == keyList.end()) {
            keyList[keyIt->second] = new set<string>();
        }
        keyList[keyIt-> second]->insert(key);
        
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(keyList.begin() == keyList.end()) {return "";}
        return *((keyList.rbegin() -> second)->begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(keyList.begin() == keyList.end()) {return "";}
        //cout<<"1 " << keyList.begin() << endl;
        return *((keyList.begin() -> second)->begin());
    }
};

/*["AllOne","inc","inc","getMaxKey","getMinKey","inc","getMaxKey","getMinKey"]
[[],["hello"],["hello"],[],[],["leet"],[],[]]*/
int main() {
    AllOne oneHere;
    oneHere.inc("hello");
    cout << oneHere.getMaxKey() << endl;
    cout << oneHere.getMinKey() << endl;
    oneHere.inc("hello");
    // for(map<int, set<string>*>::iterator it = oneHere.keyList.begin(); it != oneHere.keyList.end(); it++) {
    //     set<string>* pointer = (it->second);
    //     for(set<string>::iterator it1 = pointer->begin(); it1 != pointer->end();it1++) {
    //         cout <<it->first <<", "<< *it1 << endl;
    //     }
    // }
    cout << oneHere.getMaxKey() << endl;
    cout << oneHere.getMinKey() << endl;
    oneHere.inc("leet");
    cout << oneHere.getMaxKey() << endl;
    cout << oneHere.getMinKey() << endl;
    oneHere.inc("getMaxKey");
    cout << oneHere.getMaxKey() << endl;
    cout << oneHere.getMinKey() << endl;
    oneHere.inc("getMinKey");
    cout << oneHere.getMaxKey() << endl;
    cout << oneHere.getMinKey() << endl;
    oneHere.inc("inc");
    cout << oneHere.getMaxKey() << endl;
    cout << oneHere.getMinKey() << endl;
    oneHere.inc("a");
    cout << oneHere.getMaxKey() << endl;
    cout << oneHere.getMinKey() << endl;
    oneHere.dec("a");
    cout << oneHere.getMaxKey() << endl;
    cout << oneHere.getMinKey() << endl;
    // nums1[0] = 1;
    // nums1[1] = 2;
    // nums1[2] = 3;
    // nums2[0] = 2;
    // nums2[1] = 5;
    // nums2[2] = 6;
    // merge(nums1, 3, nums2, 3);
    // for(int i = 0; i < 6; i++) {
    //     cout << nums1[i] << endl;
    // }
    std::cout << "Hello World!\n";
}