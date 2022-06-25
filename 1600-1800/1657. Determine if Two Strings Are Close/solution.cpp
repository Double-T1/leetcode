class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if (m != n) return false;
        
        int freq1[26] = {0}, freq2[26] = {0};
        for (int i=0; i<m; i++) {
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
        }
        
        unordered_multiset<int> hashset;
        for (int i=0; i<26; i++) {
            if(freq1[i]>0) hashset.insert(freq1[i]);
        }
        
        for (int i=0; i<26; i++) {
            if (freq2[i] == 0) {
                if (freq1[i] == 0) continue;
                return false;
            }
            if (freq1[i] == 0) return false;
            auto it = hashset.find(freq2[i]);
            if (it == hashset.end()) return false;
            hashset.erase(it);
        }
        return true;
    }
};

/*
1. position doesn't matter, cuz we can always swap
2. the freq of a char isn't bind to itself, cuz we can always transform   



*/
