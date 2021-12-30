//create a disjoint set prototype
class disjointSet {
    constructor (n) {
        this.parents = new Array(n+1)
        this.ranks = new Array(n+1)

        for (let i=0; i<this.parents.length; i++) {
            this.parents[i] = i
        }
    }

    //path compression
    find (x) {
        if (x !== this.parents[x]) {
            this.parents[x] = this.find(this.parents[x])
        }
        return this.parents[x]
    }

    //naive union => union by rank is unnecessary here
    union (x,y) {
        let px = this.find(x)
        let py = this.find(y)
        if (px === py) return false //x and y are already in the same union
        this.parents[py] = px
        return true //x and y newly merged into the same union
    }
}

var findRedundantConnection = function(edges) {
    let set = new disjointSet(edges.length)
    
    for (let [v1,v2] of edges) {
        if (!set.union(v1,v2)) return [v1,v2]
    }
};

//imitate the methods of union set without instantiating an object class
var findRedundantConnection2 = function(edges) {
    let parents = new Array(edges.length+1)
    for (let i=0; i<edges.length+1; i++) {
        parents[i] = i
    }
    
    for (let [v1,v2] of edges) {
        if (!union(v1,v2,parents)) return [v1,v2]
    }
};

let union = (x,y,parents) => {
    let px = find(x,parents)
    let py = find(y,parents)
    if (px === py) return false //x and y are already in the same union
    parents[py] = px
    return true //x and y newly merged into the same union
}

let find = (x,parents) => {
    if (x !== parents[x]) {
        parents[x] = find(parents[x],parents)
    }
    return parents[x]
}

//time O(n**2)
var findRedundantConnection3 = function(edges) {
    let adj = {}
    
    for (let [v1,v2] of edges) {
        if (findPath(v1,v2,adj)) return [v1,v2]
        if(!adj[v1]) adj[v1] = []
        if(!adj[v2]) adj[v2] = []
        adj[v1].push(v2)
        adj[v2].push(v1)
    }
    return
};

let findPath = (v1,v2,adj) => {
    if (!adj[v1] || !adj[v2]) return false
    let stack = [v1]
    let visited = []
    visited[v1] = true
    while (stack.length) {
        let vertex = stack.pop()
        for (let end of adj[vertex]) {
            if (end === v2) return true
            if (!visited[end]) {
                stack.push(end)
                visited[end] = true
            }
        }
    }
    return false
}

let edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
console.log(findRedundantConnection(edges))
