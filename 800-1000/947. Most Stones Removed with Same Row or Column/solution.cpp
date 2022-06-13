class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int parent[n], size[n];
        for (int i=0; i<n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
        
        for (int i=0; i<n; i++) {
            int x = stones[i][0], y = stones[i][1];
            for (int j=i+1; j<n; j++) {
                if (stones[j][0] == x || stones[j][1] == y) 
                    unite(parent,i,j,size);
            }
        }
        
        int ans = 0;
        for (int i=0; i<n; i++) {
            int pi = find(parent,i);
            //cout << pi << " " << size[pi] << endl;
            if (size[pi] == -1) continue;
            ans += size[pi]-1;
            size[pi] = -1;
        }
        
        return ans;
    }
    
private:
    void unite (int parent[], int x, int y, int size[]) {
        int px = find(parent,x), py = find(parent,y);
        if (px == py) return;
        parent[py] = px;
        size[px] += size[py];
    }
    
    int find (int parent[], int x) {
        if (x != parent[x])
            parent[x] = find(parent,parent[x]);
        return parent[x];
    }
};

/*
is it guaranteed that a component of stones can be reduced to one stone?? yes
if an edge exist for a node, it can be removed

union find


*/
