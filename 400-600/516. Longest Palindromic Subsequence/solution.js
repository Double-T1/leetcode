var longestPalindromeSubseq = function(s) {
    return helper(s)
};

let helper = (s,left=0,right=s.length-1,memo={}) => {
    if (left in memo && right in memo[left]) return memo[left][right]
    if (!memo[left]) memo[left] = {}
    
    if (left===right) {
        memo[left][right] = 1
    } else if (left>right) {
        memo[left][right] = 0
    } else {
        if (s[left] === s[right]) {
             memo[left][right] = helper(s,left+1,right-1,memo) +2
        } else {
             memo[left][right] = Math.max(helper(s,left+1,right,memo),helper(s,left,right-1,memo))
        }
    }
    return  memo[left][right]
}

var longestPalindromeSubseq = function(s) {
    let dp = new Array(s.length).fill(0)
    
    for (let left=s.length-1; left>=0; left--) {
        let diaganol = 0
        for (let right=left; right<s.length; right++) {
            let temp = dp[right]
            if (left===right) {
                dp[right] = 1
            } else {
                if (s[left] === s[right]) {
                    dp[right] = diaganol+2
                } else {
                    dp[right] = Math.max(dp[right],dp[right-1])
                }
            }
            diaganol = temp
        }
    }
    return dp[dp.length-1]
};


