constexpr int mod = 1e9 +7;

class Solution {
private:
    int k;
public:
    int countHousePlacements(int n) {
        k = n;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        long long ans = (helper(1,false,dp) + helper(1,true,dp))%mod;
        ans = (ans*ans)%mod;
        return static_cast<int>(ans);
    }
    
private:
    int helper(int i, bool prev,vector<vector<int>>& dp) {
        if (i == k) return 1;
        if (dp[i][prev]>-1) return dp[i][prev];
        
        dp[i][prev] = helper(i+1,false,dp);
        if (!prev) dp[i][prev] += helper(i+1,true,dp);
        dp[i][prev] %= mod;
        return dp[i][prev];
    }
    
};

/*
math or dp

count one side than square it


dp:
x(i,occupied): the maximum amount of houses for i plots, with the first plot occupied or not

x(i,true) = min(x(i-1,false)+1)
x(i,false) = min(x(i-1,true))
*/
