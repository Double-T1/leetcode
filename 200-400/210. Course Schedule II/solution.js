//DFS
//time: O(V+E) depends on the matrix representation, here we use adjacency list, thus V+E. will be V^2 for adjacency matrix
//space: O(V+E)
var findOrder = function(numCourses, prerequisites) {
    let adj = {}
    for (let i=0; i<prerequisites.length; i++) {
        const [end,start] = prerequisites[i]
        if (!adj[start]) adj[start] = []
        adj[start].push(end)
    }

    //dfs
    let ans = []
    
    //needs cycle detection as well
    // 1 means not yet visited
    // 2 means visited but not yet recorded, a revisit here implies cyclicality
    // 3 means recordered and visited
    let record = new Array(numCourses).fill(1) 
    for (let course=0; course<numCourses; course++) {
        if (record[course] === 1) {
            let stack = [course]
            while (stack.length) {
                course = stack.pop()
                //specifically for explicit stack recursion 
                if (record[course] !== 1) {
                    if (record[course] === 2) {
                        ans.unshift(course)
                    }
                    record[course] = 3
                    continue
                }
                
                stack.push(course)
                record[course] = 2
                if (!adj[course]) continue
                for (let end of adj[course]) {
                    if(record[end] === 1) {
                        stack.push(end)
                    } else if (record[end] === 2) {
                        return []
                    }
                }
            }
        }
    }
    return ans
};

//complexity same as above
var findOrder2 = function(numCourses, prerequisites) {
    let adj = {}
    for (let i=0; i<prerequisites.length; i++) {
        const [end,start] = prerequisites[i]
        if (!adj[start]) adj[start] = []
        adj[start].push(end)
    }

    //dfs
    //need a cycle detection as well
    let ans = []
    // 1 means not yet visited
    // 2 means visited but not yet recorded, a revisit here implies cyclicality
    // 3 means recordered and visited
    let record = new Array(numCourses)
    for (let i=0; i<numCourses; i++) {
        if(dfs(ans,record,adj,i)) return []
    }
    return ans
};

let dfs = (ans,record,adj,course) => {
    if (record[course] === 2) return true
    if (record[course] === 3) return false

    record[course] = 2
    if (adj[course]) {
        for (let end of adj[course]) {
            if(dfs(ans,record,adj,end)) return true
        }
    }
    
    ans.unshift(course)
    record[course] = 3
    return false
}

//Kahn's Algo (revised bfs)
//go from the lowest in degree to the highest
//same complexity as above
var findOrder3 = function(numCourses, prerequisites) {
    let adj = {}
    let inDegree = new Array(numCourses)
    //prep the adjList
    //and count the indegree of each node
    for (let i=0; i<prerequisites.length; i++) {
        const [end,start] = prerequisites[i]
        if (!adj[start]) adj[start] = []
        adj[start].push(end)

        if (!inDegree[end]) inDegree[end] = 0
        inDegree[end]++
    }
    
    //start from zero in degree
    let queue = []
    for (let i=0; i<inDegree.length; i++) {
        if(!inDegree[i]) queue.push(i)
    }
    
    let ans = []
    while (queue.length) {
        let vertex = queue.shift()
        ans.push(vertex)
        if (!adj[vertex]) continue
        for (let end of adj[vertex]) {
            inDegree[end]--

            if(inDegree[end] === 0) queue.push(end)
        }
    }

    return ans.length === numCourses ? ans : []
};

let  numCourses = 3, prerequisites =[[1,2],[1,0],[0,1]]
console.log(findOrder3(numCourses,prerequisites))

