//conventional top-down dp
class Solution {
private:
    int m, n;
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        if (grid[0][0] == ')' || grid.back().back() == '(' || (m+n)%2 == 0) return false;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>((m+n)/2+1,-1)));
        return helper(dp,grid,0,0,0);
    }
private:
    bool helper(vector<vector<vector<int>>>& dp, vector<vector<char>>& grid, int i, int j, int l) {
        if (j == n || i == m || j<0 || i<0 || l<0 || l>(m+n)/2) return false;
        if (i == m-1 && j == n-1) return l == 1;
        if (dp[i][j][l]>-1) return dp[i][j][l];
        
        int curL = grid[i][j] == '(' ? l+1 : l-1;        
        return dp[i][j][l] = helper(dp,grid,i+1,j,curL) || helper(dp,grid,i,j+1,curL);
    }
};
