class Solution {
private:
    int m,n;
    int row[4] = {0,1,0,-1};
    int col[4] = {1,0,-1,0};
    
public:
    typedef tuple<int,int,int> tiii;
    
    int minimumObstacles(vector<vector<int>>& grid) {
        m = grid.size(), n= grid[0].size();
        int dist[m][n];
        memset(dist,-1,sizeof(dist));
        
        priority_queue<tiii,vector<tiii>,greater<tiii>> pq; //fromSource: current spot
        pq.emplace(grid[0][0],0,0);
        dist[0][0] = grid[0][0];
        while (!pq.empty()) {
            auto[fromS, x, y] = pq.top(); pq.pop();
            if (x == m-1 && y == n-1) return fromS;
            if (dist[x][y] > -1 && dist[x][y]<fromS) continue;
            
            for (int k=0; k<4; k++) {
                int i = x+ row[k], j = y+ col[k];
                if (i<0 || j<0 || i>=m || j>=n) continue;
                if (dist[i][j]>-1 && dist[i][j]<=fromS+grid[i][j]) continue;
                
                dist[i][j] = fromS + grid[i][j];
                pq.emplace(dist[i][j],i,j);
            }
        }
        
        return m*n;
    }
};
