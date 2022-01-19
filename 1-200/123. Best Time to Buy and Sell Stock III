//heap out of memory
var maxProfit = function(prices) {
    return helper(prices)
};

let helper = (prices,i=0,k=2,holding=false,memo={}) => {
    if (i in memo && k in memo[i] && holding in memo[i][k]) return memo[i][k][holding]
    if (memo[i] === undefined) memo[i] = {}
    if (memo[i][k] === undefined) memo[i][k] = {}

    if (k===0 || i === prices.length) {
        memo[i][k][holding] = 0
    } else {
        if (holding) {
            //sell or hold
            memo[i][k][holding] = Math.max(helper(prices,i+1,k-1,false,memo)+prices[i],helper(prices,i+1,k,holding,memo))
        } else {
            //buy or hold, k>0
            memo[i][k][holding] = Math.max(helper(prices,i+1,k,true,memo)-prices[i],helper(prices,i+1,k,holding,memo))
        }
    }
    return memo[i][k][holding] 
}

var maxProfit2 = function(prices) {
    let dp = new Array(3)
        .fill()
        .map(() => new Array(2))
    //holding is 1, not is 0
    for (let i=prices.length; i>=0; i--) {
        for (let k=2; k>=0; k--) {
            if (k===0 || i === prices.length) {
                dp[k][1] = 0
                dp[k][0] = 0  
            } else {
                dp[k][0] = Math.max(dp[k][1]-prices[i],dp[k][0])
                dp[k][1] = Math.max(dp[k-1][0]+prices[i],dp[k][1])
            }
        }
    }
    return dp[2][0]
};
let  prices = [1,2,3,4,5]
console.log(maxProfit2(prices))
