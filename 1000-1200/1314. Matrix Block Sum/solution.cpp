class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size()-1, n = mat[0].size()-1;
        for (int i=0; i<=m; i++) {
            for (int j=0; j<=n; j++) {
                if (i>0) mat[i][j] += mat[i-1][j];
                if (j>0) mat[i][j] += mat[i][j-1];
                if (i>0 && j>0) mat[i][j] -= mat[i-1][j-1];
            }
        }
        
        vector<vector<int>> ans(m+1,vector<int>(n+1,0));
        for (int i=0; i<=m; i++) {
            for (int j=0; j<=n; j++) {
                ans[i][j] = getSize(min(i+k,m),min(j+k,n),max(0,i-k),max(0,j-k),mat);
            }
        }
        return ans;
    }
    
private:
    int getSize(int i1, int j1, int i2, int j2, vector<vector<int>>& mat) {
        int ans = mat[i1][j1];
        if (i2>0) ans -= mat[i2-1][j1];
        if (j2>0) ans -= mat[i1][j2-1];
        if (i2>0 && j2>0) ans += mat[i2-1][j2-1];
        return ans;
    }
    
};

/*
brute force: O(m*n*k*k*4) => TLE

prefix sum

1. dp[i][j] = sum of matrix[0][0] to matrix[i][j] 
2. to get size of (i1,j1,i2,j2) => dp[i1][j1]+dp[i2-1][j2-1]-dp[i1][j2-1]-dp[i1-1][j2]
3. for each mat[m][n], get the size of (m+k,n+k,m-k,n-k); 
!! don't go out of bounds



*/
