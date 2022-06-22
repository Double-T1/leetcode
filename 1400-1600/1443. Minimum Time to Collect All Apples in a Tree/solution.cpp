class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> tree(n);
        for (auto& edge: edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        
        bool visited[n];
        memset(visited,0,sizeof(visited));
        return dfs(tree,hasApple,0,visited);
    }
    
private:
    int dfs(vector<vector<int>>& tree, vector<bool>& hasApple, int cur, bool visited[]) {
        visited[cur] = true;
        int ans = 0;
        for (int next: tree[cur]) {
            if (visited[next]) continue;
            int len = dfs(tree,hasApple,next,visited);
            
            ans += (len>0 || hasApple[next]) ? len + 2 : 0;
        }
        //cout << cur << " " << ans << endl;
        return ans;
    }
    
};
