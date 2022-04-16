//time: O(t^2n) => on the edge of TLE => more of O(t*(t/n)*n) in reality => O(t^2)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<vector<int>> memo(coins.size()+1,vector<int>(amount+1,-1));
        int ans = helper(coins,memo,amount,0);
        return ans == INT_MAX? -1 : ans;
    }
    
private:
    int helper(vector<int>& coins, vector<vector<int>>& memo, int amount, int i) {
        if (amount == 0) return 0;
        if (memo[i][amount]>-1) return memo[i][amount];
        if (i == coins.size() || amount<coins[i]) return memo[i][amount] = INT_MAX;
        int dup = amount, ans = INT_MAX, cur = 0;
        while (dup>=0) {
            int x = helper(coins,memo,dup,i+1);
            ans = x<INT_MAX? min(ans,x+cur) : ans;
            dup -= coins[i];
            cur++;
        }
        return memo[i][amount] = ans;
    }
};

//time: O(t*n)
//space: O(t)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int dp[amount+1];
        dp[0] = 0;
        for (int t = 1; t<=amount; t++) {
            dp[t] = INT_MAX;
            for (int c: coins) {
                if (t<c) break;
                if(dp[t-c] < INT_MAX) dp[t] = min(dp[t],dp[t-c]+1);
            }
        }
        return dp[amount] == INT_MAX? -1: dp[amount];
    }
};

//top-down
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int> memo(amount+1,-1);
        int x = helper(coins,amount,memo);
        return x<INT_MAX? x : -1;
    }
    
private:
    int helper(vector<int>& coins, int amount, vector<int>& memo) {
        if (amount == 0) return 0;
        if (memo[amount]>-1) return memo[amount];
        
        int ans = INT_MAX;
        for(int coin : coins) {
            if (coin>amount) break;
            int x = helper(coins,amount-coin,memo);
            if (x<ans-1) ans = x+1; 
        }
        return memo[amount] = ans;
    }
};
