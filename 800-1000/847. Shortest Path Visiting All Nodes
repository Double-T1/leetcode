var shortestPathLength = function(graph) {
    //find APSP with BFS
    let adj = []
    for (let i=0; i<graph.length; i++) {
        adj[i] = bfs(graph,i)
    }
    adj.push(new Array(graph.length).fill(0))
    return helper(adj,adj.length-1)
};

//((n^2)*(2^n))
let helper = (adj,node,bitmask=0,memo=[]) => {
    if (node in memo && bitmask in memo[node]) return memo[node][bitmask]
    if (memo[node] === undefined) memo[node] = [] 

    let ans = Number.MAX_SAFE_INTEGER
    for (let i=0; i<adj[node].length; i++) {
        let bit = 1<<i
        if ((bitmask&bit)>0) continue
        ans = Math.min(ans,helper(adj,i,bitmask|bit,memo)+adj[node][i])
    }
    memo[node][bitmask] = ans === Number.MAX_SAFE_INTEGER? 0 : ans
    return memo[node][bitmask]
}

let bfs = (graph,i) => {
    let arr = []
    arr[i] = 0
    let dist = 1
    let queue = [i]
    while (queue.length) {
        let size = queue.length
        while (size) {
            let current = queue.pop()
            for (let end of graph[current]) {
                if (arr[end] !== undefined) continue
                arr[end] = dist
                queue.unshift(end)
            }
            size--
        }
        dist++
    }
    return arr
}

let graph = [[1,2,3],[0],[0],[0]] 
console.log(shortestPathLength(graph))






/**
 * goal: find the shortest path
 * rules: may start and stop at any node, revisit nodes multiple times, and reuse edges.
 * 1. try all possibles paths => compare the length of each
 * => try nont visited nodes/edges first, until no unvisited edges remain while unvisited nodes remain
 * go for the visited nodes
 * each node/edge has three stage:
 * 1. unvisited => priority to traverse
 * 2. visited => after priorities are depleted
 * 3. sealed => can't be traversed through at all
 */
