class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> adj[n];
        for (int i=0; i<n; i++) {
            int p = words[i].size();
            for (int j=i+1; j<n; j++) {
                int q = words[j].size();
                if (abs(p-q) == 1) {
                    if (p>q && oneDiff(words[i],words[j])) {
                        adj[j].push_back(i);
                    } else if (q>p && oneDiff(words[j],words[i])) {
                        adj[i].push_back(j);
                    }
                } 
            }
        }
        
        int ans = 0;
        int memo[n];
        memset(memo,-1,sizeof(memo));
        for (int i=0; i<n; i++) {
            ans = max(ans,dfs(adj,i,memo));
        }
        return ans;
    }
    
private:
    int dfs(vector<int> adj[], int i, int memo[]) {
        if (memo[i]>-1) return memo[i];
        
        memo[i] = 0;
        for (auto next: adj[i]) {
            memo[i] = max(memo[i], dfs(adj,next,memo));
        }
        return ++memo[i];
    }
    
    
    //string a is longer than string b
    bool oneDiff(string& a, string& b) {
        bool one = false;
        int n = b.size();
        for (int i=0, j=0; j<n; i++, j++) {
            if (a[i] != b[j]) {
                if (one) return false;
                one = true;
                j--;    
            } 
        }
        return true;
    }
};
