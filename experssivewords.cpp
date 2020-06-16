    bool compareWords(string stretch, string original){
        int stretchPosition = 0, originalPosition = 0;
        while(originalPosition != original.size()) {
            if(stretchPosition == stretch.size()) {return false;}
            char oChar = original[originalPosition];
            if(stretch[stretchPosition] != oChar){return false;}
            int stretchCount = 0,originalCount = 0;
            while(originalPosition != original.size() && original[originalPosition] == oChar) {
                originalCount++;
                originalPosition++;
            }
            
            while(stretchPosition != stretch.size() && stretch[stretchPosition] == oChar) {
                stretchCount++;
                stretchPosition++;
            }
            
            cout << stretch << ", " << original<<", " << oChar << ", " << originalCount << ", " << stretchCount << endl;
            if(!(stretchCount == originalCount || (stretchCount > originalCount && stretchCount >= 3))) {return false;}
        }
        
        return stretchPosition == stretch.size();
    }
    int expressiveWords(string S, vector<string>& words) {
        int resultCount = 0;
        for(int i = 0; i < words.size(); i++) {
            if(compareWords(S, words[i])) resultCount ++;
        }
        
        return resultCount;
    }

int main () {
    vector<string> words{"hello", "hi", "helo"};
    cout << expressiveWords("heeellooo", words) << endl;
    cout << "hello world" << endl;
}


// int main () {
//     vector<string> words{"dinnssoo","ddinso","ddiinnso","ddiinnssoo","ddiinso","dinsoo","ddiinsso","dinssoo","dinso"};
//     cout << expressiveWords("dddiiiinnssssssoooo", words) << endl;
//     cout << "hello world" << endl;
// }