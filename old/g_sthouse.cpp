
int searchStore(int house, vector<int>& stores, int begin, int end) {
    if(end - begin < 2) {
        int beginDiff = abs(stores[begin] - house);
        int endDiff = abs(stores[end] - house);
        return endDiff < beginDiff ?stores[end] : stores[begin];
    }
    int mid = (begin + end)/ 2;
    if(stores[mid] == house) return house;
    if(stores[mid] > house) return searchStore(house, stores, begin, mid);
    else return searchStore(house, stores, mid + 1, end);
}

int main () {
    int nHouses;
    cin >> nHouses;
    vector<int> houses;
    int input;
    for(int i = 0; i < nHouses; i++) {
        cin >> input;
        houses.push_back(input);
    }
    int nStores;
    cin >> nStores;
    vector<int> stores;
    for(int i = 0; i < nStores; i++) {
        cin >> input;
        stores.push_back(input);
    }

    sort(stores.begin(), stores.end());
    for(int i = 0; i < nHouses; i++) {
        cout << searchStore(houses[i], stores, 0 , nStores - 1) << endl;
    }
}