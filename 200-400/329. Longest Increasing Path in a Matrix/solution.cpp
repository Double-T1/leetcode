class Solution {
private:
    int row[4] = {0,1,0,-1};
    int col[4] = {1,0,-1,0};
    int r,c;
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        r = matrix.size(), c = matrix[0].size();
        int dp[r*c];
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                ans = max(ans,dfs(matrix,i,j,dp));
            }
        }
        return ans;
    }
    
private:
    int dfs(vector<vector<int>>& matrix, int i, int j, int dp[]) {
        if (dp[i*c+j]>-1) return dp[i*c+j];
        int val = matrix[i][j], ans = 0;
        for (int k=0; k<4; k++) {
            int m = i+row[k], n = j+col[k];
            if (m<0 || n<0 || m>=r || n>=c || matrix[m][n]<=val) 
                continue;
            ans = max(ans,dfs(matrix,m,n,dp));
        }
        return dp[i*c+j] = ans+1;
    }
    
};
