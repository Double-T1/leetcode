class Solution {
public:
    typedef vector<int> vi;
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vi adj[n];
        for (auto& edge: richer) {
            adj[edge[1]].push_back(edge[0]);
        }
        
        vi ans(n,-1);
        for (int i=0; i<n; i++)
            helper(adj,ans,i,quiet);
        
        return ans;
    }
private:
    int helper(vi adj[], vi& ans, int cur, vi& quiet) {
        if (ans[cur]>-1) return ans[cur];
        
        ans[cur] = cur;
        for (int next : adj[cur]) {
            int j = helper(adj,ans,next,quiet);
            if (quiet[j]<quiet[ans[cur]]) 
                ans[cur] = j;
        }
        return ans[cur];
    }
};

/*
every element/person i, find the element/person j who are not richer and with the smallest value of q

definitely richer => a to i's b
make the edge b to a, indicating b is richer than a, hence could be its j 

can we get definitely equal?? i doubt that

1. create a directed edge, adjlist
2. dfs, recurse

!!! transitivity guaranteed to hold



*/
