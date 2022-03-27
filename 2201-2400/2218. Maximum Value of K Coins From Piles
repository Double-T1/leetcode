var maxValueOfCoins = function(piles, k) {
    piles.forEach(pile => {
        let prev = 0
        for (let i=0; i<pile.length; i++) {
            pile[i] = prev + pile[i]
            prev = pile[i] 
        }
    })
    return helper(piles,k)
};

let helper = (piles,k,i=0,memo=[]) => {
    if (k === 0) return 0
    if (i === piles.length) return Number.MIN_SAFE_INTEGER
    if (i in memo && k in memo[i]) return memo[i][k]
    if (memo[i] === undefined) memo[i] = []
    
    let ans = helper(piles,k,i+1,memo)
    for (let j=1; j<=k && j-1<piles[i].length; j++) {
        ans = Math.max(ans,helper(piles,k-j,i+1,memo)+piles[i][j-1])
    }
    memo[i][k] = ans
    return ans
}





/**
choose k times
find max, need to choose from top to bottom
a1 + a2 + ... + an = k => TLE for brute force
greedy doesn't work
try DP
need to record the current pointer for each subarr

prepare from 0 to piles[i].length for each

*/
