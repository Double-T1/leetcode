//time:O(n^2)
var findLongestChain = function(pairs) {
    pairs.sort((a,b) => a[0]-b[0])
    let dp = []
    let max = 1
    for (let i=0; i<pairs.length; i++) {
        dp[i] = 1
        let s = pairs[i][0]
        for (let j=0; j<i; j++) {
            if (pairs[j][1]<s) dp[i] = Math.max(dp[i],dp[j]+1) 
        }
        max = Math.max(max,dp[i])
    }
    return max
};


//greedy O(n)
var findLongestChain2 = function(pairs) {
    pairs.sort((a,b) => a[1]-b[1])
    let len = 1
    let e = pairs[0][1]
    for (let i=1; i<pairs.length; i++) {
        if (pairs[i][0]>e) {
            e = pairs[i][1]
            len++
        }
    }
    return len
};
