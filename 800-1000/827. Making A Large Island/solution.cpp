class Solution {
private: 
    int row[4] = {0,1,0,-1};
    int col[4] = {1,0,-1,0};
    int n;
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int parent[n*n], size[n*n];
        for (int i=0; i<n*n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 0) continue;
                int cur = i*n+j;
                if (i>0 && grid[i-1][j] == 1) unite(parent,size,cur,cur-n);
                if (j>0 && grid[i][j-1] == 1) unite(parent,size,cur,cur-1);
                ans = max(ans,size[cur]);
            }
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) continue;
                ans = max(ans,makeBridge(grid,parent,size,i,j));           
            }
        }
        return ans;
    }
    
private:
    int makeBridge(vector<vector<int>>& grid, int parent[], int size[], int i, int j) {
        int ans = 1;
        unordered_set<int> seen;
        for (int k=0; k<4; k++) {
            int p = i+row[k], q = j+col[k];
            if (p<0 || p>=n || q<0 || q>=n || grid[p][q] == 0) continue;
            int b = find(parent,p*n+q);
            if (seen.count(b)) continue;
            seen.insert(b);
            ans += size[b];
        }       
        return ans;
    }
    
    void unite(int parent[], int size[], int a, int b) {
        int pa = find(parent,a), pb = find(parent,b);
        if (pa == pb) return;
        parent[pb] = pa; 
        size[pa] += size[pb];
    }
    
    int find(int parent[], int x) {
        if (parent[x] != x) {
            parent[x] = find(parent,parent[x]);
        }
        return parent[x];
    }
};

/*
1. union find all the 1s => a size for the parent
2. for every 0, check the parents of all its neighbors => if diff, find the max pair sum + 1
=> two traversal
1. union find all the 1s first, then check the 0s


edge case: no zero => return the largest land
*/
