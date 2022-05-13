//top-down
class Solution {
public:
    int maxProfit(vector<int>& prices) {         
        int dp[prices.size()][3][2];
        memset(dp,-1,sizeof(dp));
        return helper(prices,2,0,1,dp);
    }
    
private:
    int helper(vector<int>& prices, int k, int i, int toBuy, int memo[][3][2]) {
        if (k == 0 || (i==prices.size())) return 0;
        if (memo[i][k][toBuy]>-1) return memo[i][k][toBuy];
        
        if (toBuy) {
            memo[i][k][toBuy] = max(helper(prices,k,i+1,toBuy,memo),helper(prices,k,i+1,0,memo)-prices[i]);
        } else {
            memo[i][k][toBuy] = max(helper(prices,k,i+1,toBuy,memo),helper(prices,k-1,i+1,1,memo)+prices[i]);
        }
        return memo[i][k][toBuy];
    }
};

//bottom-up
class Solution {
public:
    int maxProfit(vector<int>& prices) {         
        int dp[3][2];
        //0 is toBuy == false, 1 is toBuy == true
        for (int i=prices.size(); i>=0; i--) {
            for (int k=2; k>=0; k--) {
                if (k == 0 || i == prices.size()) {
                    dp[k][1] = 0;
                    dp[k][0] = 0;
                } else {
                    dp[k][1] = max(dp[k][1],dp[k][0]-prices[i]);
                    dp[k][0] = max(dp[k][0],dp[k-1][1]+prices[i]);
                }
            }
        }
        
        return dp[2][1];
    }
};
