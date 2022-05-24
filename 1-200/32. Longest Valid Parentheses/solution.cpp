class Solution {
public:
    int longestValidParentheses(string s) {
        int dp[s.size()];
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') continue;
            int j = i-1;
            for (int j=i-1; j>=0;) {
                if (s[j] == '(') {
                    dp[i] = dp[i-1] + 2;
                    if (j>0) dp[i] += dp[j-1];
                    break;
                } else if (dp[j] == 0) {
                    break;
                } else {
                    j -= dp[j];
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
