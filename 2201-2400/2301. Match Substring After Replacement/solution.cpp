class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n = s.size(), m = sub.size();
        unordered_map<char,unordered_set<char>> mp;
        
        for (auto& p: mappings)
            mp[p[0]].insert(p[1]);
        
        
        for (int i=0, j; i<=n-m; i++) {
            bool hasMatch = true;
            for (j=0; j<m; j++) {
                char c = s[i+j], c2 = sub[j];
                if (c != c2 && mp[c2].find(c) == mp[c2].end()) {
                    hasMatch = false;
                    break;
                } 
            }
            if (hasMatch) return true;
        }
        return false;
    }
};

/*
O(m*n)

1. prep a vector of unordered_map, where each index holds a map of possible replacements
=> prep it through mappings
2. n^2 time 


*/
