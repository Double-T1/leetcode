class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for (auto& edge: pre) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int> ans;
        int visited[n];
        memset(visited,0,sizeof(visited));
        for (int i=0; i<n; i++) {
            if (visited[i] == 0 && dfs(ans,visited,i,adj)) return {};
        }
        return ans;
    }
private:
    bool dfs(vector<int>& ans, int visited[], int cur, vector<vector<int>>& adj) {
        if (visited[cur] == 1) return true;
        if (visited[cur] == 2) return false;
        visited[cur] = 1;
        if (!adj[cur].empty()) {
            for (auto& next: adj[cur]) {
                if (dfs(ans,visited,next,adj)) return true;
            }
        }
        visited[cur] = 2;
        ans.push_back(cur);
        return false;
    }
};

/*
kahn's algo
dfs



*/
