class Solution {
private:
    int i=0;
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto& edge: connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int low[n], id[n];
        memset(low,-1,sizeof(low));
        vector<vector<int>> ans;
        dfs(ans,adj,0,-1,low,id);
        return ans;
    }
    
private:
    
    void dfs(vector<vector<int>>& crit, vector<int> adj[], int cur, int p, int low[], int id[]) {
        id[cur] = i;
        low[cur] = i++;
        
        
        for (auto next : adj[cur]) {
            if (next == p) continue;
            if (low[next] > -1) {
                low[cur] = min(id[next],low[cur]);
            } else {
                dfs(crit,adj,next,cur,low,id);
                low[cur] = min(low[cur],low[next]);
                if (id[cur]<low[next]) {
                    crit.push_back({cur,next});
                }
            }
        }
    }
};
