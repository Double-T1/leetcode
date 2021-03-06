//DP
//time: O(n^2)
var twoCitySchedCost = function(costs) {
    return helper(costs)
};

let helper = (costs,i=0,numOfA=0,memo=[]) => {
    if (i === costs.length) {
        if (numOfA === costs.length/2) return 0
        return Number.MAX_SAFE_INTEGER
    }
    if (numOfA > costs.length/2) return Number.MAX_SAFE_INTEGER
    if (i in memo && numOfA in memo[i]) return memo[i][numOfA]
    if (memo[i] === undefined) memo[i] = []
    memo[i][numOfA] = Math.min(helper(costs,i+1,numOfA+1,memo)+costs[i][0],helper(costs,i+1,numOfA,memo)+costs[i][1])
    return memo[i][numOfA]
}

//greedy
//time: O(nlogn)
//observation:
//1. sort for the highest tradeoff for choosing A at the front
//2. if same, then sort for the smallest A
var twoCitySchedCost = function(costs) {
    costs.sort((a,b) => {
        let da = a[1]-a[0], db = b[1]-b[0]
        if (da === db) {
            return a[0]-b[0]
        } else {
            return db-da
        }
    })
    let ans = 0, k = 0
    for (let i=0; i<costs.length; i++) {
        ans += costs[i][k]
        if (i+1 === costs.length/2) k = 1
    }
    return ans
};

//we can actually improve the actual average runtime of the greedy case
//giving that we don't need the actual sorted sequence, but just the right first half and second half(where the first half are all for picking a)
//hence, quickselect would be ideal, since on average, it won't need to go through all the elements
//yet, the asymptotic analysis stay the same
