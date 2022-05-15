class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        vector<int> adj[patience.size()];
        for (auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int dist[patience.size()];
        memset(dist,-1,sizeof(dist));
        dist[0] = 0;
        queue<int> qu;
        qu.push(0);
        int l = 0, ans = 0;
        while (!qu.empty()) {
            int size = qu.size();
            l += 2;
            while (size--) {
                auto node = qu.front(); qu.pop();
                for (auto next: adj[node]) {
                    if (dist[next] > -1) continue;
                    dist[next] = l + 1;
                    if (patience[next]<l) {
                        int r = l%patience[next];
                        if (r == 0) r=patience[next];
                        dist[next] += l -r;
                    }
                    
                    ans = max(ans,dist[next]);
                    qu.push(next);
                } 
            }
        }
        return ans;
    }
};

/*
goal: 
1. find the amount of time for every data servers to send and retrieve message from the master server
=> dub the length between master and data as l

for one signal to return, it takes 2*l time
if patience[i]<2*l => find the last second the server will send a new message:
the last second: patience[i]*k < 2*l, find the remaining seconds from the last message after the first return from the master is received.
=> r = 2*l%patience[i], if r == 0 => r = patience[i].

=> for the server, the max time is 4*l - r + 1; 
*/
