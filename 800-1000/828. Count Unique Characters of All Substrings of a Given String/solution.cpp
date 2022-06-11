class Solution {
public:
    int uniqueLetterString(string s) {
        int prevIndex[26], curIndex[26];
        memset(prevIndex,-1,sizeof(prevIndex));
        memset(curIndex,-1,sizeof(curIndex));
        int n = s.size(), ans = 0;
        for (int i=0; i<n; i++) {
            auto c = s[i];
            if (curIndex[c-'A'] > -1) {
                int cur = curIndex[c-'A'];
                ans += (cur-prevIndex[c-'A'])*(i-cur);
            } 
            prevIndex[c-'A'] = curIndex[c-'A'];
            curIndex[c-'A'] = i;
        }
        
        for (int j=0; j<26; j++) {
            ans  += (curIndex[j]-prevIndex[j])*(n-curIndex[j]);
        }
        
        return ans;
    }
};
