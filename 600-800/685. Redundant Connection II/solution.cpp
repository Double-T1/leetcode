//soltuion 1
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int parent[n+1];
        for (int i=0; i<n+1; i++) {
            parent[i] = i;
        }

        vector<int> adj[n+1];
        vector<int> cycle, later;
        for (auto& edge: edges) {
            auto u = edge[0], v = edge[1];
            if(!unite(parent,u,v,later)) cycle = {u,v};
            adj[u].push_back(v);
        }
        
        if (later.empty()) return cycle;
        return helper(adj,later);
    }
    
private:
    bool unite (int parent[], int u, int v, vector<int>& later) {
        int pu = find(parent,u), pv = find(parent,v);
        if (pv != v && later.empty()) later = {u,v};
        if (pu == pv) return false;
        parent[pv] = pu;
        return true;
    }
    
    int find (int parent[], int x) {
        if (x != parent[x]) {
            parent[x] = find(parent,parent[x]);
        }
        return parent[x];
    }
    
    vector<int> helper(vector<int> adj[], vector<int>& later) {
        queue<int> qu;
        int target = later[1];
        qu.push(target);
        while (!qu.empty()) {
            auto cur = qu.front(); qu.pop();
            for (auto next: adj[cur]) {
                if (next == target) return {cur,target};
                qu.push(next);
            }
        }
        return later;
    }
};

/*
either there is a node with two parents
or no root 

if node A has an incoming redundant edge, it either comes from one of its descendants or others(including parent of parent and nodes on other subtrees).

if the edge comes from its descendants, then it creates a cycle. meaning starting from node A, we could travel back to A.

if the edge is from others, it can actually replace the original edge. 
=> just return the later edge 

1. build an adjacency list
2. while building, make sure that there is precisely one node with no incoming edges (ie the root)
3. if 2 no longer applies, meaning a children links back to our temporary root. Record this edge as the redundant edge. since if at the end n new root emerges, this is the redundant root.
4. at the same time, if a node has more than one incoming edge, record both. in this case, 3 is no longer applicable.
5. run a dfs from the node with two incoming edges. if it travels back to itself, than the edge that leads the cycle back is redundant. or else, the last of two is to be returned.

prep:
1. parent to determine component, and if 

*/

//solution 2
//the better solution
//even though shares the same complexity, the code is cleaner and the idea is easier. only one pass is required
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size(), first = -1, second = -1, cycle = -1;
        int parent[n+1], inEdge[n+1];
        for (int i=0; i<n+1; i++) {
            parent[i] = i;
            inEdge[i] = -1;
        }

        for (int i=0; i<n; i++) {
            auto u = edges[i][0], v = edges[i][1];
            if (inEdge[v] != -1) {
                first = inEdge[v];
                second = i;
                continue;
            }
            inEdge[v] = i;
            
            int pu = find(parent,u);
            if (pu == v) cycle = i;
            else parent[v] = pu;
        }
        
        if (second == -1) return edges[cycle];
        if (cycle == -1) return edges[second];
        return edges[first];
    }
    
private:
    int find (int parent[], int x) {
        if (x != parent[x]) {
            parent[x] = find(parent,parent[x]);
        }
        return parent[x];
    }
};


/*





*/
