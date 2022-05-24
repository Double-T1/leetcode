class Solution {
public:
    int longestValidParentheses(string s) {
        int dp[s.size()];
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') continue;
            int j = i-1;
            if (j>=0 && s[j] == '(') {
                dp[i] = 2;
                if (j>0) dp[i] += dp[j-1];
            } else if (j>= 0 && dp[j]>0 && (j -= dp[j])>=0 && s[j] == '(') {
                dp[i] = 2 + dp[i-1];
                if (j>0) dp[i] += dp[j-1];
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
