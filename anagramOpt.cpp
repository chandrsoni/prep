
vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    int m = p.size();
    int n = s.size();
    if(n < m) return result;
    vector<int> pCharMap(26, 0);
    vector<int> sCharMap(26, 0);
    for(int i = 0 ; i < m; i++) {
        pCharMap[p[i]- 'a']++;
    }
    for(int i = 0; i < m; i++) {
        sCharMap[s[i] - 'a']++;
    }
    
    if(sCharMap == pCharMap) {
        result.push_back(0);
    }
    
    for(int i = m; i < n; i++) {
        sCharMap[s[i-m] - 'a']--;
        sCharMap[s[i] - 'a']++;
        if(sCharMap == pCharMap) result.push_back(i - m + 1);
    }
    return result;
}
