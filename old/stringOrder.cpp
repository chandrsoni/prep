bool isStringBigger(string& s1, string& s2, unordered_map<char, int>& charOrder) {
    for(int i = 0; i < min(s1.size(), s2.size()); i++) {
        if(charOrder[s1[i]] > charOrder[s2[i]]){ return false; }
        if(charOrder[s1[i]] < charOrder[s2[i]]){ return true; }
    }
    if(s1.size() > s2.size()) {return false;}
    return true;
}

bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> charOrder;
    for(int i = 0; i < order.size(); i++) {
        charOrder[order[i]] = i;
    }

    for(int i = 0; i < words.size() - 1; i++) {
        if(!isStringBigger(words[i], words[i+1], charOrder)) {
            return false;
        }
    }
    return true;
}

int main() {
    string order;
    cin >> order;
    int wordCount;
    cin >> wordCount;
    vector<string> words;
    string input;
    for(int i = 0; i < wordCount; i++) {
        cin >> input;
        words.push_back(input);
    }
    cout << isAlienSorted(words, order) << endl;
    std::cout << "Hello World!\n";
}