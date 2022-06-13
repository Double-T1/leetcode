var numRollsToTarget = function(n, k, target) {
    return helper(k,n,target)
};

let helper = (k,n,target,memo={}) => {
    if (n in memo && target in memo[n]) return memo[n][target]
    if (memo[n] === undefined) memo[n] = {}

    if (n === 0) {
        if (target === 0) {
            memo[n][target] = 1
        } else {
            memo[n][target] = 0
        }
    } else {
        let count = 0
        for (let i=1; i<=Math.min(k,target); i++) {
            count += helper(k,n-1,target-i,memo)
        }
        memo[n][target] = count%((10**9)+7)
    }
    return memo[n][target]
}

let  n = 30, k = 30, target = 500
console.log(numRollsToTarget(n,k,target))
