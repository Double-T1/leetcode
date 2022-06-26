class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i == j || i+j == n-1) {
                    if (grid[i][j] == 0) return false;
                } else {
                    if (grid[i][j] != 0) return false;
                }
            }
        }
        return true;
    }
};

/*
diaganol: 
1. 0,0 => 1,1 => 2,2 => 3,3: i == j
2. 0,3 => 1,2 => 2,1 => 3,1: i+j = n-1


*/
