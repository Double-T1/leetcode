class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        iota(parent.begin(),parent.end(),0);
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            if (unite(u,v,parent)) return edge;
        }
        return edges.back();
    }
private:
    bool unite(int a,int b, vector<int>& parent) {
        int pa = find(a,parent), pb = find(b,parent);
        if (pa == pb) return true;
        parent[pb] = pa;
        return false;
    }
    
    int find(int x, vector<int>& parent) {
        if (x != parent[x]) {
            parent[x] = find(parent[x],parent);
        }
        return parent[x];
    }
};
