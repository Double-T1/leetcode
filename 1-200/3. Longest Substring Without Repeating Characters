//time: O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashmap;
        int maxLen = 0;
        for (int j=0, i=-1; j<s.size(); j++) {
            char& c = s[j];
            if (hashmap.count(c)>0) 
                i = max(i,hashmap[c]);
            maxLen = max(maxLen, j-i);
            hashmap[c] = j;
        }
        return maxLen;
    }
};

//getting rid of hashing actually makes it much faster
//time: O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256,-1);
        int maxLen = 0;
        for (int j=0, i=-1; j<s.size(); j++) {
            char& c = s[j];
            if (dict[c]>i) 
                i = dict[c];
            maxLen = max(maxLen, j-i);
            dict[c] = j;
        }
        return maxLen;
    }
};
