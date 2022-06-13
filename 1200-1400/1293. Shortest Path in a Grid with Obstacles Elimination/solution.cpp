class Solution {
private:
    int row[4] = {0,1,0,-1};
    int col[4] = {1,0,-1,0};
    
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return 0;
        
        queue<tuple<int,int,int>> qu; //[i,j,ob]
        int visited[m][n];
        memset(visited,-1,sizeof(visited));
        visited[0][0] = 0;
        
        qu.emplace(0,0,0);
        int l = 0;
        while (!qu.empty()) {
            int size = qu.size();
            l++;
            while (size--) {
                auto[i,j,k_] = qu.front(); qu.pop();
                
                for (int p=0; p<4; p++) {
                    int x = i+row[p], y = j+col[p];
                    if (x == m-1 && y == n-1) return l;
                    
                    if (x<0 || y<0 || x>=m || y>=n) 
                        continue;
                    
                    int curK = k_ + grid[x][y];
                    if (curK > k || (visited[x][y] != -1 && curK >= visited[x][y])) 
                        continue;
                    visited[x][y] = curK;
                    qu.emplace(x,y,curK);
                }
            }
        }
        return -1;
    }
};
