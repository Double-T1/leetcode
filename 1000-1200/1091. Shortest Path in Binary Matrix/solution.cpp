class Solution {
private:
    int n;
    int next[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if (n == 1) return 1;
        
        queue<pair<int,int>> qu; 
        qu.emplace(0,0);
        grid[0][0] = 1;
        int len = 1;
        while (!qu.empty()) {
            int size = qu.size();
            len++;
            while (size--) {
                auto[i,j] = qu.front(); qu.pop();
                for(int k=0; k<8; k++) {
                    int p = i + next[k][0], q = j + next[k][1];
                    if (p == n-1 && q == n-1) return len;
                    if (!isValid(grid,p,q)) continue;
                    grid[p][q] = 1;
                    qu.emplace(p,q);
                }
            }
        }
        return -1;
    }
    
    bool isValid(vector<vector<int>>& grid, int i, int j) {
        return i>=0 
            && i<n
            && j>=0
            && j<n
            && grid[i][j] == 0;
    }
};
