class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        bool adj[n][n];
        memset(adj,0,sizeof(adj));
        for (auto& edge: pre) {
            int u = edge[0], v = edge[1];
            adj[u][u] = true;
            adj[v][v] = true;
            adj[u][v] = true;
        }
        
        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]); 
                }
            }
        }
        
        int m = queries.size();
        vector<bool> ans(m);
        for (int i=0; i<m; i++) {
           ans[i] = adj[queries[i][0]][queries[i][1]];
        }
        
        return ans;
    }
};
