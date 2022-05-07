class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char,char> hashmap1;
        unordered_map<char,char> hashmap2;
        for (int i=0; i<s.size(); i++) {
            if (hashmap1.find(s[i]) != hashmap1.end()) {
                if (hashmap1[s[i]] != t[i]) return false;
            } else {
                if (hashmap2.find(t[i]) != hashmap2.end()) return false;
                hashmap2[t[i]] = s[i];
                hashmap1[s[i]] = t[i];
            }
        }
        return true;
    }
};
