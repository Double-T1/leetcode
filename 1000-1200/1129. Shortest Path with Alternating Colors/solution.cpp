class Solution {
public:
    typedef tuple<int,int,int> tiii;
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> adj[2][n];
        for (auto& edge: redEdges) {
            adj[0][edge[0]].push_back(edge[1]);
        }
        for (auto& edge: blueEdges) {
            adj[1][edge[0]].push_back(edge[1]);
        }
        
        vector<vector<int>> dist(2,vector<int>(n,INT_MAX));
        dist[0][0] = 0;
        dist[1][0] = 0;
        
        vector<int> ans(n,-1);
        ans[0] = 0;
        queue<pair<int,int>> qu;
        qu.emplace(0,0);
        qu.emplace(0,1);
        int len = 0;
        while (!qu.empty()) {
            int size = qu.size();
            len++;
            while (size--) {
                auto [node,c] = qu.front(); qu.pop();
                for (auto next: adj[c^1][node]) {
                    if(dist[c^1][next] != INT_MAX) continue; 
                    dist[c^1][next] = len;
                    qu.emplace(next,c^1);
                    ans[next] = ans[next] == -1 ? dist[c^1][next]
                        : min(ans[next],dist[c^1][next]);
                }
            }
        }
        return ans;
    }
};

/*
two adjList
alternating

relaxing criteria
1. if dis(u,v) > dis(u,w) + dis(w,v) => update 
2. two set of distance, indicating whether the dis is reached last by red or blue

color:
0: red
1: blue

*/
