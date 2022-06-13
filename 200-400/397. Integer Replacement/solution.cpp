class Solution {
public:
    typedef unordered_map<int,int> umii;
    
    int integerReplacement(int n) {
        umii dp;
        return helper(n,dp);
    }
    
private:
    int helper(int n, umii& dp) {
        if (n == 1) return 0;
        if (dp.find(n) != dp.end()) return dp[n];
        
        if (n%2 == 0) {
            dp[n] = 1 + helper(n/2,dp);
        } else {
            dp[n] = 2 + min(helper(n/2+1,dp),helper(n/2,dp));
        }
        return dp[n];
    }
};
