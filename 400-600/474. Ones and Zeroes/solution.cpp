class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {        
        int dp[m+1][n+1];
        memset(dp,-1,sizeof(dp));
        dp[0][0] = 0;
        int ans = 0;
        for (auto& s : strs) {
            int z =0, one = 0;
            for (auto c: s) {
                if (c == '0') z++;
                else one++;
            }
            
            for (int i=m; i>=0 && i>=z; i--) {
                for (int j=n; j>=0 && j>=one; j--) {
                    if (dp[i-z][j-one]>-1) {
                        dp[i][j] = max(dp[i-z][j-one]+1,dp[i][j]);
                        ans = max(ans,dp[i][j]);
                    }
                }
            }
        }
        return ans;
    }
};
