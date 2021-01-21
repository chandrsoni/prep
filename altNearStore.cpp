int nearestStore(int house, vector<int> &stores, int startIndex, int endIndex) {
    if(endIndex == startIndex) {
        return stores[startIndex];
    }
    
    if(endIndex == startIndex + 1) {
        return stores[endIndex] - house >= house - stores[startIndex]
            ? stores[startIndex] : stores[endIndex];
    }
    
    int midIndex = (startIndex + endIndex)/2;
    if(stores[midIndex] > house) {
        return nearestStore(house, stores, startIndex, midIndex);
    }
    return nearestStore(house, stores, midIndex, endIndex);
}

vector<int> nearestStore(vector<int>& houses, vector<int>& stores) {
    sort(stores.begin(), stores.end());
    vector<int> closestStores;
    for(int i = 0; i < houses.size(); i++) {
        closestStores.push_back(nearestStore(houses[i], stores, 0, stores.size() -  1));
    }
    
    return closestStores;
}

int main() {
    // vector<int> houses{5,10, 17};
    // vector<int> stores {1,5,20,11,16};
    // vector<int> houses{2,4,2};
    // vector<int> stores {5,1,2,3};
    vector<int> houses{4, 8, 1, 1};
    vector<int> stores {5, 3, 1, 2, 6};
    vector<int> nearestStores = nearestStore(houses, stores);
    
    for(int i = 0; i < nearestStores.size(); i++) {
        cout << nearestStores[i] << endl;
    }
    std::cout << "Hello World!\n";
}