//solution 1
//top-down
//ac but super slow
//time: O(n*k*n)
//space: O(n*k)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> memo(prices.size(),vector<int>(k+1,-1));
        return helper(prices,k,0,memo);
    }
    
private:
    int helper(vector<int>& prices, int k, int i, vector<vector<int>>& memo) {
        if (k == 0 || i == prices.size()) return 0;
        if (memo[i][k]>-1) return memo[i][k];
        
        memo[i][k] = helper(prices,k,i+1,memo);
        for (int j=i+1; j<prices.size(); j++) {
            memo[i][k] = max(memo[i][k],helper(prices,k-1,j+1,memo)+prices[j]-prices[i]);
        }
        return memo[i][k];
    }
};

//solution 2
//bottom-up from solution 1
//time: O(n*k*n)
//space: O(n*k)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int dp[prices.size()+1][k+1];
        for (int i=prices.size(); i>=0; i--) {
            for (int k_=k; k_>=0; k_--) {
                if (k_ == 0 || i == prices.size()) {
                    dp[i][k_] = 0;
                } else {
                    dp[i][k_] = dp[i+1][k_];
                    for (int j=i+1; j<prices.size(); j++) {
                        dp[i][k_] = max(dp[i][k_],dp[j+1][k_-1]+prices[j]-prices[i]);
                    }
                }
            }
        }
        
        
        return dp[0][k];
    }
};
