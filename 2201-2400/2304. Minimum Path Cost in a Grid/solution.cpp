class Solution {
public:
    typedef vector<vector<int>> vvi;
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ans = INT_MAX, m = grid.size(), n = grid[0].size();
        vvi dp(m,vector<int>(n,-1));
        for (int j=0; j<n; j++) {
            ans = min(ans,helper(grid,moveCost,dp,j));
        }
        return ans;
    }
    
private:
    int helper(vvi& grid, vvi& moveCost, vvi& dp, int j, int i=0) {
        if (i == grid.size()-1) return grid[i][j];
        if (dp[i][j]>-1) return dp[i][j];
        
        int val = grid[i][j];
        dp[i][j] = helper(grid,moveCost,dp,0,i+1) + moveCost[val][0];
        for (int y=1; y<grid[0].size(); y++) {
            dp[i][j] = min(dp[i][j],helper(grid,moveCost,dp,y,i+1)+moveCost[val][y]);
        }
        
        return dp[i][j] += val;
    }
};
