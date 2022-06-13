constexpr int mod = 1e9 + 7;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(target+1,vector<int>(n+1,-1));
        return helper(target,n,k,dp);
    }
    
private:
    int helper(int target, int n, int k, vector<vector<int>>& dp) {
        if (n == 0) {
            return target == 0;
        }
        if (dp[target][n]>-1) return dp[target][n];
        
        int limit = min(target,k), ans = 0;
        for (int i=1; i<=limit; i++) {
            ans += helper(target-i,n-1,k,dp);
            ans %= mod;
        }
        return dp[target][n] = ans;
    }
};
