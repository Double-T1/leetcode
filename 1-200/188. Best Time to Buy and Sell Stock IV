var maxProfit = function(k, prices) {
    let dp = new Array(k+1)
        .fill()
        .map(() => new Array(2))
    //holding is 1, not is 0
    for (let i=prices.length; i>=0; i--) {
        for (let m=k; m>=0; m--) {
            if (m === 0 || i===prices.length) {
                dp[m][0] = 0
                dp[m][1] = 0
            } else {
                dp[m][0] = Math.max(dp[m][0],dp[m][1]-prices[i])
                dp[m][1] = Math.max(dp[m][1],dp[m-1][0]+prices[i])
            }
        }
    }
    return dp[k][0]
};

let k = 2, prices = [1,1,0]
console.log(maxProfit(k,prices))
