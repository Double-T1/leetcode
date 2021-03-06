//DP
//top down with memoization
//time: O(len*m*n)
//space: O(len*m*n)
var findMaxForm = function(strs, m, n) {
    let ones = []
    let zeros = []
    for (let i=0; i<strs.length; i++) {
        ones[i] = 0
        zeros[i] = 0
        for (let j=0; j<strs[i].length; j++) {
            if (strs[i][j] === '1') {
                ones[i]++
            } else {
                zeros[i]++
            }
        }
    }
    return helper(ones,zeros,m,n)
};

//find the subsequence with a maximal length
//s.t. 0s<=m and 1s<=n 
let helper = (ones,zeros,m,n,index=0,memo={}) => {
    if (index in memo && m in memo[index] && n in memo[index][m]) return memo[index][m][n]
    if (index === ones.length || (m===0 && n===0)) {
        return 0
    } else {
        if (!memo[index]) memo[index] = {}
        if (!memo[index][m]) memo[index][m] = {}
        let zero = zeros[index]
        let one = ones[index]

        //excluding strs[index]
        let len = helper(ones,zeros,m,n,index+1,memo)
        //including strs[index]
        if (m>=zero && n>=one) len = Math.max(len,helper(ones,zeros,m-zero,n-one,index+1,memo)+1)
        memo[index][m][n] = len
        return len
    }
}

//DP
//bottom up
//time: O(len*m*n)
//space: O(m*n)
var findMaxForm2 = function(strs, m, n) {
    //construct the table
    let dp = new Array(n+1)
        .fill()
        .map(() => new Array(m+1).fill(0))
    
    for (let str of strs) {
        //count the ones and zeros
        let ones = 0
        let zeros = 0
        for (let char of str) {
            if (char === '0') {
                zeros++
            } else {
                ones++
            }
        }

        //since we will be using a block from the topleft, 
        //traversing the whole table from bottom right to top left 
        //avoids updating blocks on information updated by the 
        //same string earlier
        for (let i=n; i>=0; i--) {
            for (let j=m; j>=0; j--) {
                if (j>=zeros && i>=ones) dp[i][j] = Math.max(dp[i][j],1+dp[i-ones][j-zeros])
            }
        }
    }
    return dp[n][m]
};
