class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> matrix(n,0);
        matrix[0] = 1;
        for (int i=0; i<m; i++) {
            int left = 0;
            for (int j=0; j<n; j++) {
                matrix[j] += left; 
                left = matrix[j];
            }
        }
        return matrix.back();
    }
};

