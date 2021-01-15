vector<int> findAnagrams(string s, string p) {
    sort(p.begin(), p.end());
    int n = s.size(), m = p.size();
    vector<int> result;
    for(int i = 0; i < n - m + 1; i++) {
        string subs = s.substr(i, m);
        sort(subs.begin(), subs.end());
        if(subs == p) {
            result.push_back(i);
        }
    }
    return result;
}