class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n,vector<int>(n,INT_MAX));
        int i = 0;
        for (auto& edges: graph) {
            for (int j: edges) {
                adj[i][j] = 1;
            }
            i++;
        }
        
        for (int m=0; m<n; m++) {
            for (int i=0; i<n; i++) {
                if (i == m || adj[i][m] == INT_MAX) continue;
                for (int j=i+1; j<n; j++) {
                    if (m == j || adj[m][j] == INT_MAX) continue;
                    adj[i][j] = min(adj[i][j],adj[i][m] + adj[m][j]);
                    adj[j][i] = adj[i][j];
                }
            }
        }
        
        int limit = 1 << n;
        vector<vector<int>> dp(limit,vector<int>(n,INT_MAX));
        int ans = INT_MAX;
        for (int mask=1; mask<limit; mask++) {
            for (int i=0; i<n; i++) {
                int bit = 1 << i;
                if ((mask&bit) == 0) continue;
                int prevMask = mask^bit;
                if (prevMask == 0) dp[mask][i] = 0;
                else for (int j=0; j<n; j++) {
                    if ((prevMask&(1<<j)) == 0) continue;
                    dp[mask][i] = min(dp[mask][i],dp[prevMask][j] + adj[j][i]);
                }
                if (mask == limit-1) 
                    ans = min(ans,dp[mask][i]);
            }
        }
        return ans;
    }
};

/*
there is a distance for between every node => every node has an edge with one another
=> weighted
find the weight?
APSP
floyd warshall


shortest path that visits all node => simpler version of traveling salesman

dp[mask][last]



*/
