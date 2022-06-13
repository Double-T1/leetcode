class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        bool hasChar[n][26];
        memset(hasChar,0,sizeof(hasChar));
        for (int i=0; i<n; i++) {
            for (auto c: words[i]) {
                hasChar[i][c-'a'] = true;
            }
        }
        
        int ans =0;
        for (int i=0; i<n; i++) {
            for (int j=i-1; j>=0; j--) {
                int cur = words[i].size() * words[j].size();
                for (int k=0; k<26; k++) {
                    if (hasChar[i][k] && hasChar[j][k]) {
                        cur = 0;
                        break;
                    }
                }
                ans = max(ans,cur);
            }
        }
        
        return ans;
    }
};
