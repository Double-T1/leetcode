//make sure it is acyclical
//time: O(V+E)
//space: O(V+E) 
//C++
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        //how is the vectors initialized??
        for (auto edge : prerequisites) {
            //why can't we decompse as auto [u,v] : pre??
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }
        
        vector<int> visited(numCourses,0);
        for (int i=0; i<numCourses; i++) {
            if (visited[i] == 0 && hasCycle(visited,adj,i)) return false;
        }
        return true;
    }
    
private:
    bool hasCycle(vector<int>& visited, vector<vector<int>>& adj, int cur) {
        if (visited[cur] == 1) return true;
        if (visited[cur] == 2) return false;
        visited[cur] = 1;
        if (adj[cur].size()>0) {
            for (int next : adj[cur]) {
                if (hasCycle(visited,adj,next)) return true;
            }
        }
        visited[cur] = 2;
        return false;
    }
};



//JS
var canFinish = function(numCourses, prerequisites) {
    let adj = {}
    for (let i=0; i<prerequisites.length; i++) {
        const [end,start] = prerequisites[i]
        if (!adj[start]) adj[start] = []
        adj[start].push(end)
    }

    //dfs
    let record = new Array(numCourses)
    //undefined means not yet visited
    //1 means visited but not recorded, a revisited of this state ipmlies a circle
    //2 means done
    for (let i=0; i<numCourses; i++) {
        if(!dfs(adj,i,record)) return false
    }
    return true
};

let dfs = (adj,course,record) => {
    if (record[course] === 1) return false
    if (record[course] === 2) return true

    record[course] = 1
    if (adj[course]) {
        for (let end of adj[course]) {
            if(!dfs(adj,end,record)) return false
        }
    } 
    record[course] = 2
    return true
}

let  numCourses = 2, prerequisites = [[1,0]]
console.log(canFinish(numCourses,prerequisites))
