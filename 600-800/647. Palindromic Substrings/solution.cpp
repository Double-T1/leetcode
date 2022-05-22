class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0, n = s.size();
        for (auto i=0; i<n; i++) {
            for (auto j=i, k=i; j>=0 && k<n && s[j] == s[k]; j--, k++) {
                ans++;
            }
            for (auto j=i, k=i+1; j>=0 && k<n && s[j] == s[k]; j--, k++) {
                ans++;
            }
        }
        return ans;
    }
};
