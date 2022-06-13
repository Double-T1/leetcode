class NumMatrix {
private:
    vector<vector<int>> mat;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i=0; i<n; i++) {
            mat.push_back({});
            for (int j=0; j<m; j++) {
                mat[i].push_back(matrix[i][j]);
                if (i>0) mat[i][j] += mat[i-1][j];
                if (j>0) mat[i][j] += mat[i][j-1];
                if (i>0 && j>0) mat[i][j] -= mat[i-1][j-1];
                //cout << mat[i][j] << endl;
             }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = mat[row2][col2];
        if (row1>0) ans -= mat[row1-1][col2];
        if (col1>0) ans -= mat[row2][col1-1];
        if (row1>0 && col1>0) ans += mat[row1-1][col1-1];
        //cout << ans << endl;
        return ans;
    }
};
