class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<int> adj(n,0);
    
        for (auto& edge: roads) {
            adj[edge[0]]++;
            adj[edge[1]]++;
        }
        
        sort(adj.begin(),adj.end());
        for (int i=0; i<n; i++) {
            ans += (long long)adj[i]*(i+1);
        }
        return ans;
    }
};
