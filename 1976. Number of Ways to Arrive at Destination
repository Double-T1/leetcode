var countPaths2 = function(n, roads) {
    let mod = 10**9 + 7
    let start = 0
    let end = n-1

    let adj = {}
    for (let i=0; i<roads.length; i++) {
        let [v1,v2,weight] = roads[i]
        if (!adj[v1]) adj[v1] = []
        if (!adj[v2]) adj[v2] = []
        adj[v1].push([v2,weight])
        adj[v2].push([v1,weight])
    }

    let dist = []
    let waysToReach = [1]
    dist[start] = 0
    let minHeap = [[start,0]]
    while (minHeap.length) {
        let [vertex,distFromS] = remove(minHeap)
        if (adj[vertex]) {
            for (let [target,weight] of adj[vertex]) {
                let val = (weight+distFromS)
                if (dist[target] === undefined || dist[target]>val) {
                    dist[target] = val
                    waysToReach[target] = waysToReach[vertex]
                    insert(minHeap,target,val)
                } else if (dist[target] === val) {
                    waysToReach[target] += waysToReach[vertex]
                    waysToReach[target] %= mod
                }
                
            }
        } 
        
    }

    return waysToReach[end]
}

let remove = (minHeap) => {
    let ans = minHeap[0]
    swap(minHeap,0,minHeap.length-1)
    minHeap.pop()
    if (minHeap.length===0) return ans

    //bubble down
    let currentIndex = 0
    let val = minHeap[0][1]
    while (2*currentIndex+1<minHeap.length) {
        let index1 = 2*currentIndex+1
        let index2 = 2*currentIndex+2
        let child1 = minHeap[index1]
        let child2 = minHeap[index2]

        if (child2===undefined || child1[1]<child2[1]) {
            if (child1[1]<val) {
                swap(minHeap,index1,currentIndex)
                currentIndex = index1
            } else {
                break
            }
        } else if (child2[1]<val) {
            swap(minHeap,index2,currentIndex)
            currentIndex = index2
        } else {
            break
        }
    }
    return ans
}

let insert = (arr,target,val) => {
    arr.push([target,val])
    let currentIndex = arr.length-1

    while (currentIndex>0) {
        let parentIndex = currentIndex%2 === 1? (currentIndex-1)/2 : (currentIndex-2)/2

        if (arr[parentIndex][1]>val) {
            swap(arr,parentIndex,currentIndex) 
            currentIndex = parentIndex
        } else {
            break
        }
    }
    return arr
}

let swap = (arr,a,b) => {
    let temp = arr[a]
    arr[a] = arr[b]
    arr[b] = temp
    return
}
