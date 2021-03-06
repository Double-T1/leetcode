//lazy dijkstra
//time: O(ElogV)
//space: O(V+E)
var networkDelayTime = function(times, n, k) {
    let adj = {}
    for (let i=0; i<times.length; i++) {
        const[source,target,weight] = times[i]
        if (!adj[source]) adj[source] = []
        adj[source].push([target,weight])
    }
    
    let dist = new Array(n)
    let minHeap = [[k,0]]
    while (minHeap.length) {
        let pair = remove(minHeap) //return the vertex with the smallest distance(weight) from k
        let [vertex,distFromK] = pair 
        if (dist[vertex-1] === undefined || dist[vertex-1] > distFromK) {
            dist[vertex-1] = distFromK
            if (!adj[vertex]) continue
            for (let [target,weight] of adj[vertex]) {
                insertion(minHeap,[target,weight+distFromK])
            }
        }
    }
    
    let max = 0
    for (let i=0; i<dist.length; i++) {
        if (dist[i] === undefined) return -1
        max = Math.max(max,dist[i])
    }
    
    return max
};

//smallest num on the left hand side
let insertion = (minHeap,pair) => {
    let val = pair[1]
    minHeap.push(pair)
    let currentIndex = minHeap.length-1
    //bubble the inserted value up to its place
    
    while (currentIndex>0) {
        let parentIndex = currentIndex%2===1? (currentIndex-1)/2 : (currentIndex-2)/2

        if (minHeap[parentIndex][1]>val) {
            swap(minHeap,parentIndex,currentIndex)
            currentIndex = parentIndex
        } else {
            break
        }
    }   
    return 
}

let remove = (minHeap) => {
    let ans = minHeap[0]
    swap(minHeap,0,minHeap.length-1)
    minHeap.pop()
    if (minHeap.length === 0) return ans

    let val = minHeap[0][1]
    let currentIndex = 0

    while (2*currentIndex+1<minHeap.length) {
        let index1 = 2*currentIndex+1
        let index2 = 2*currentIndex+2
        let child1 = minHeap[index1]
        let child2 = minHeap[index2]

        if (child2 === undefined && child1[1]>val) {
            break
        } else if ((child2 === undefined || child1[1]<child2[1]) && val>child1[1]) {
            swap(minHeap,currentIndex,index1)
            currentIndex = index1
        } else if (child1[1]>=child2[1] && val>child2[1]) {
            swap(minHeap,currentIndex,index2)
            currentIndex = index2
        } else {
            break
        }
    }

    return ans
}

let swap = (arr,a,b) => {
    let temp = arr[a]
    arr[a] = arr[b]
    arr[b] = temp
    return
}

//optimized dijkstra with indexed PQ
//time: O(V+E)
//space: O(V+E)
var networkDelayTime2 = function(times, n, k) {
    let adj = {}
    for (let i=0; i<times.length; i++) {
        const[source,target,weight] = times[i]
        if (!adj[source]) adj[source] = []
        adj[source].push([target,weight])
    }

    let dist = new Array(n)
    let minIndexedHeap = [[k,0]]
    let heapDict = {}
    heapDict[k] = 0 //records the index of the according vertex in indexed PQ
    while (minIndexedHeap.length) {
        let pair = remove2(heapDict,minIndexedHeap) //return the vertex with the smallest distance(weight) from k
        let [vertex,distFromK] = pair 
        if (dist[vertex-1] === undefined || dist[vertex-1] > distFromK) {
            dist[vertex-1] = distFromK
            if (!adj[vertex]) continue
            for (let [target,weight] of adj[vertex]) {
                update2(heapDict,minIndexedHeap,target,weight+distFromK)
            }
        }
    }
    
    let max = 0
    for (let i=0; i<dist.length; i++) {
        if (dist[i] === undefined) return -1
        max = Math.max(max,dist[i])
    }
    
    return max
};

let update2 = (heapDict,minIndexedHeap,target,val) => {
    let index = heapDict[target] 
    if (index !== undefined) {
        if (minIndexedHeap[index][1]>val) {
            minIndexedHeap[index][1] = val
            bubbleUp(minIndexedHeap,index,heapDict)
        }
    } else {
        insertion2(minIndexedHeap,[target,val],heapDict)
    }
    return
}


//smallest num on the left hand side
let insertion2 = (minHeap,pair,heapDict) => {
    minHeap.push(pair)
    let currentIndex = minHeap.length-1
    heapDict[pair[0]] = currentIndex
    //bubble the inserted value up to its place
    bubbleUp(minHeap,currentIndex,heapDict)
    return 
}

let bubbleUp = (minHeap,currentIndex,heapDict) => {
    let val = minHeap[currentIndex][1]
    while (currentIndex>0) {
        let parentIndex = currentIndex%2===1? (currentIndex-1)/2 : (currentIndex-2)/2

        if (minHeap[parentIndex][1]>val) {
            swap2(minHeap,parentIndex,currentIndex,heapDict)
            currentIndex = parentIndex
        } else {
            break
        }
    }   
    return
}

let remove2 = (heapDict,minHeap) => {
    let ans = minHeap[0]
    swap2(minHeap,0,minHeap.length-1,heapDict)
    minHeap.pop()
    heapDict[ans[0]] = undefined
    if (minHeap.length === 0) return ans

    let [vertex,val] = minHeap[0]
    let currentIndex = 0
    heapDict[vertex] = currentIndex

    while (2*currentIndex+1<minHeap.length) {
        let index1 = 2*currentIndex+1
        let index2 = 2*currentIndex+2
        let child1 = minHeap[index1]
        let child2 = minHeap[index2]

        if (child2 === undefined && child1[1]>=val) {
            break
        } else if ((child2 === undefined || child1[1]<child2[1]) && val>child1[1]) {
            swap2(minHeap,currentIndex,index1,heapDict)
            currentIndex = index1
        } else if (child1[1]>=child2[1] && val>child2[1]) {
            swap2(minHeap,currentIndex,index2,heapDict)
            currentIndex = index2
        } else {
            break
        }
    }

    return ans
}

let swap2 = (arr,a,b,heapDict) => {
    heapDict[arr[a][0]] = b
    heapDict[arr[b][0]] = a

    let temp = arr[a]
    arr[a] = arr[b]
    arr[b] = temp
    return
}

//for Directed positive weight graph only
//FILO branch and bound (?)
//time: O()
var networkDelayTime3 = function(times, n, k) {
    let adj = {}
    //time: O(E)
    //space: O(E)
    for (let i=0; i<times.length; i++) {
        const[source,target,weight] = times[i]
        if (!adj[source]) adj[source] = []
        adj[source].push([target,weight])
    }
    
    let dist = new Array(n) //space: O(V)
    let stack= [[k,0]]
    dist[k-1] = 0
    while (stack.length) {
        let [vertex,distFromK] = stack.pop()
        if (!adj[vertex]) continue
        //O()
        for (let [target,weight] of adj[vertex]) {
            if (dist[target-1] === undefined || dist[target-1]>weight+distFromK) {
                dist[target-1] = weight+distFromK
                stack.push([target,dist[target-1]])    
            }
        }  
    }

    let max = 0
    for (let i=0; i<dist.length; i++) {
        if (dist[i] === undefined) return -1
        max = Math.max(max,dist[i])
    }
    
    return max
};

//FIFO branch and bound (?)
var networkDelayTime4 = function(times, n, k) {
    let adj = {}
    //time: O(E)
    //space: O(E)
    for (let i=0; i<times.length; i++) {
        const[source,target,weight] = times[i]
        if (!adj[source]) adj[source] = []
        adj[source].push([target,weight])
    }
    
    let dist = new Array(n) //space: O(V)
    let stack= [[k,0]]
    dist[k-1] = 0
    while (stack.length) {
        let [vertex,distFromK] = stack.shift()
        if (!adj[vertex]) continue
        //O()
        for (let [target,weight] of adj[vertex]) {
            if (dist[target-1] === undefined || dist[target-1]>weight+distFromK) {
                dist[target-1] = weight+distFromK
                stack.push([target,dist[target-1]])    
            }
        }  
    }

    let max = 0
    for (let i=0; i<dist.length; i++) {
        if (dist[i] === undefined) return -1
        max = Math.max(max,dist[i])
    }
    
    return max
};

let times =[[1,2,1],[2,3,7],[1,3,4],[2,1,2]], n=3,k=2
console.log(networkDelayTime2(times,n,k))
