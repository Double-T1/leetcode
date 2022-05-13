//time: O(m*n)
//space: O(1)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int a = m+n-1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j] == 0) continue;
                mat[i][j] = a;
                if(i>0) mat[i][j] = min(mat[i][j],mat[i-1][j]+1);
                if(j>0) mat[i][j] = min(mat[i][j],mat[i][j-1]+1);
            }
        }
        
        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                if (mat[i][j] == 0) continue;
                if (i<m-1) mat[i][j] = min(mat[i][j],mat[i+1][j]+1);
                if (j<n-1) mat[i][j] = min(mat[i][j],mat[i][j+1]+1);
            }
        }
        
        return mat;
    }
};

/*
make every 1 to -1
traverse twice, 
first time traversing from topleft to bottomright 
=> x(i,j) = min(x[i-1][j],x[i][j-1])+1 if (x[i][j] == 1)
second for traversing from bottomright to topleft
=> x(i,j) = min(x[i][j],x[i+1][j]+1,x[i][j+1]+1) if (x[i][j] > 0)
*/
