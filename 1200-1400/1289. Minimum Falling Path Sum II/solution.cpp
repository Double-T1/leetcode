//solution 1
//time: O(n^3) 
//should work, got a passed all testcase but took too long
class Solution {
private:
    int n;
    
public:
    typedef vector<vector<int>> vvi;
    
    int minFallingPathSum(vvi& grid) {
        n = grid.size();
        vvi dp(n,vector<int>(n+1,20000));
        return helper(grid,0,n,dp);
    }
    
private:    
    int helper(vvi& grid, int i, int occuCol, vvi& dp) {
        if (i == n) return 0;
        if (dp[i][occuCol]<20000) return dp[i][occuCol];
        
        int ans = 20000;
        for (int j=0; j<n; j++) {
            if (j == occuCol) continue;
            ans = min(ans,helper(grid,i+1,j,dp) + grid[i][j]);
        }
        return dp[i][occuCol] = ans; 
    } 
};

//solution 2
//with greedy, since we only want the smallest
//time: O(n*n)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int fm = 0, sm = 0, pos = -1, n = grid.size();
        for (int i=0; i<n; i++) {
            int fm2 = INT_MAX, sm2 = INT_MAX , pos2 = -1;
            for (int j=0; j<n; j++) {
                auto cur = j == pos? sm : fm;
                if (fm2 > cur + grid[i][j]) {
                    sm2 = fm2;
                    fm2 = cur+grid[i][j];
                    pos2 = j;
                } else sm2 = min(sm2,cur+grid[i][j]);
            }
            fm = fm2, sm = sm2, pos = pos2;
        }
        return fm;
    }
};
