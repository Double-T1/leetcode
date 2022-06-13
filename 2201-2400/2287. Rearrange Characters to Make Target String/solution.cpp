class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int dict[26];
        memset(dict,0,sizeof(dict));
        for (auto c: target)
            dict[c-'a']++;
        
        int total[26];
        memset(total,0,sizeof(total));
        for (auto c: s)
            total[c-'a']++;
        
        int ans = INT_MAX;
        for (int i=0; i<26; i++) {
            if (dict[i] == 0) continue;
            int x = total[i]/dict[i];
            ans = min(ans,x);
        }
        
        return ans;
    }
};
