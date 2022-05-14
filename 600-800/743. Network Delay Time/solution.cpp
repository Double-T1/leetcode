class Solution {    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for (auto& edge: times) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].emplace_back(v,w);
        }
        
        int dist[n+1];
        for (int i=1; i<n+1; i++) dist[i] = INT_MAX;
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.emplace(0,k);
        
        while(!pq.empty()) {
            auto[fromS,u] = pq.top(); pq.pop();
            if (fromS>dist[u]) continue;
            
            for (auto&[v,w]: adj[u]) {
                if (w+fromS>=dist[v]) continue;
                dist[v] = w+fromS;
                pq.emplace(w+fromS,v);
            }
        }
        
        int ans = 0;
        for (int i=1; i<n+1; i++) {
            ans = max(ans,dist[i]); 
        }
        return ans == INT_MAX? -1 : ans;
    }
};
