class Trie {
    unordered_map<char, Trie*> children;
    bool finishedWord;
    public:
    Trie() {
        finishedWord = false;
    }
    void addWord(string s) {
        if(s.size() <= 0) {
            finishedWord = true;
            return;
        }
        
        auto child = children.find(s[0]);
        if(child == children.end()) {
            children[s[0]] = new Trie();    
        }

        return children[s[0]]->addWord(s.substr(1)); 
    }
    
    vector<string> findWord(string currentWord) {
        vector<string> words;
        if(currentWord.size() == 0) {
            for(auto it = children.begin(); it != children.end();it++) {
                auto childWords = (it->second)->findWord(currentWord);
                for(int i = 0; i < childWords.size(); i++) {
                    words.push_back(it->first + childWords[i]);
                }
            }
            
            if (finishedWord) {
                words.push_back("");
            }
            
            return words;
        }
        
        auto charChild = children.find(currentWord[0]);
        if(charChild == children.end()) {
            return words;
        }
        auto childWords = (charChild->second)->findWord(currentWord.substr(1));
        for(int i = 0; i < childWords.size(); i++) {
            words.push_back(charChild->first + childWords[i]);
        }
        
        return words;
    }
};

int main() {
    vector<string> words{"i love leetcode", "island", "ironman", "i love you"};
    Trie wordTrie;
    for(int i = 0; i < words.size(); i++) {
        wordTrie.addWord(words[i]);
    }
    string input = "i love lotto";
    string inputCheck;
    for (int i = 0; i < input.size(); i++) {
        inputCheck +=input[i];
        auto matchingWords = wordTrie.findWord(inputCheck);
        cout << "['";
        for (int j = 0; j < matchingWords.size(); j++) {
            cout << matchingWords[j] << "','";
        }
        cout << "]" << endl;
    }
    std::cout << "Hello World!\n";
}