class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for (auto& edge: flights) {
            int from = edge[0], to = edge[1], p = edge[2];
            adj[from].emplace_back(to,p);
        }
        
        vector<int> dist(n,-1);
        dist[src] = 0;
        vector<int> dup(dist.begin(),dist.end());
        
        k++;
        queue<int> qu;
        qu.push(src);
        while (k--) {
            int size = qu.size();
            while (size--) {
                auto u = qu.front(); qu.pop();
                for (auto&[v,w] : adj[u]) {
                    if (dup[v] == -1 || dup[v]>w+dist[u]) {
                        dup[v] = w+dist[u];
                        qu.push(v);
                    }
                }
            }
            dist = dup;
        }
        return dist[dst];
    }
};
