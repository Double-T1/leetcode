class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n];
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                if (canTrigger(bombs[i],bombs[j])) adj[i].push_back(j);
                if (canTrigger(bombs[j],bombs[i])) adj[j].push_back(i);
            }
        }
        
        int ans = 0;
        for (int i=0; i<n; i++) {
            int l = 1;
            int visited[n];
            memset(visited,0,sizeof(visited));
            visited[i] = 1;
            queue<int> qu;
            qu.push(i);
            while (!qu.empty()) {
                int size = qu.size();
                while (size--) {
                    auto cur = qu.front(); qu.pop();
                    for (auto next: adj[cur]) {
                        if (visited[next] == 1) continue;
                        l++;
                        qu.push(next);
                        visited[next] = 1;
                    }
                }
            }
            ans = max(ans,l);
        }
        return ans;
    }
    
private:    
    bool canTrigger(vector<int>& a, vector<int>& b) {
        long long x = a[0]-b[0], y = a[1]-b[1], r = a[2];
        return x*x + y*y <= r*r;
    }
};
