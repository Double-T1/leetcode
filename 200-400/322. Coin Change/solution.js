var coinChange = function(coins, amount) {
    let arr = new Array(amount+1).fill(-1)
    arr[0] = 0
    
    for (let i=0; i<amount+1; i++) {
        if (arr[i]>= 0) {
            for (let j=0; j<coins.length; j++) {
                arr[i+coins[j]] = arr[i+coins[j]] > 0 ? Math.min(arr[i+coins[j]],arr[i]+1)
                        : arr[i] + 1
            }
        }
    }
    
    return arr[amount]
};
