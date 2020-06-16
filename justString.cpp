
    
    string addLeftJustifiedWord(vector<string>& words, int maxWidth,int currentWidth, int beginIndex, int endIndex) {
        cout << "called left " << beginIndex << ", " << endIndex << endl;
        string result;
        for(int i = beginIndex; i < endIndex - 1; i++) {
            result += words[i];
            result += ' ';
        }
        result += words[endIndex-1];
        result += string(maxWidth - result.size(), ' ');
        cout << "half result:" << result << endl;
        return result;
    }
    string addFullJustifiedWord(vector<string>& words, int maxWidth,int currentWidth, int beginIndex, int endIndex) {
        cout << "called full " << beginIndex << ", " << endIndex << endl;
        int wordCount = endIndex - beginIndex;
        if(wordCount == 1) {
            return addLeftJustifiedWord(words, maxWidth, currentWidth, beginIndex, endIndex);
        }
        int totalSpaces = (maxWidth - currentWidth + wordCount);
        int numSpaces = totalSpaces / (wordCount - 1);
        int remSpaces = totalSpaces % (wordCount - 1);
        
        string result;
        
        for(int i = beginIndex; i < endIndex - 1; i++) {
            result += words[i];
            int currentSpaces = numSpaces;
            if(remSpaces > 0) {
                currentSpaces++;
                remSpaces--;
            }
            result += string(currentSpaces, ' ');
        }
        result += words[endIndex - 1];
        cout << "full result:" << result << endl;
        return result;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int currentWordIndex = 0;
        if(words.size() < 1){
            return vector<string>();
        }
        int currentWidth = 0;
        vector<string> result;
        for(int i = 0; i < words.size(); i++) {
            cout << i << ", " << words[i] << endl;
            if(currentWidth + words[i].size() > maxWidth) {
                // ADD A word here
                result.push_back(addFullJustifiedWord(words, maxWidth, currentWidth, currentWordIndex, i));
                currentWordIndex = i;
                currentWidth = 0;
            }
            currentWidth +=(words[i].size() + 1);
        }
        result.push_back(addLeftJustifiedWord(words, maxWidth, currentWidth, currentWordIndex, words.size()));
        
        return result;
    }
int main () {
    vector<string> words{"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
    fullJustify(words, 16);
    cout << "hello world" << endl;
}