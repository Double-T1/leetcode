//you need at least n-1 edges for n vertices to be all connected
//if there are k components, then it takes k moves to make them one component
//APSP
//practice Floyd-Warshall
//time: O(v**3)
var findTheCity = function(n, edges, distanceThreshold) {
    //calculate APSP first
    //use adj matrix
    let adjM = new Array(n)
        .fill()
        .map(() =>new Array(n))
    
    for (let [v1,v2,w] of edges) {
        adjM[v1][v1] = 0
        adjM[v2][v2] = 0
        adjM[v1][v2] = w
        adjM[v2][v1] = w
    }


    for (let k=0; k<n; k++) {
        for (let i=0; i<n; i++) {
            for (let j=0; j<n; j++) {
                if (adjM[i][j] === undefined) adjM[i][j] = Number.MAX_SAFE_INTEGER
                if (adjM[i][k] === undefined) adjM[i][k] = Number.MAX_SAFE_INTEGER
                if (adjM[k][j] === undefined) adjM[k][k] = Number.MAX_SAFE_INTEGER
                adjM[i][j] = Math.min(adjM[i][j],adjM[i][k]+adjM[k][j])
            }
        }
    }

    let min = Number.MAX_SAFE_INTEGER 
    let city = null
    for (let i=0; i<n; i++) {
        let count = 0
        for (let j=0; j<n; j++) {
            if (i!==j && adjM[i][j]<=distanceThreshold) {
                count++
            }
        }
        if (count <= min) {
            min = count
            city = i
        } 
    }
    return city
};

let n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
console.log(findTheCity(n,edges,distanceThreshold))
