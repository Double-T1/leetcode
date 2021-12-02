//recursion
//time: O(len*half)
//space: O(len*half)
var canPartition = function(nums) {
    let sum = 0
    for (let num of nums) {
        sum += num
    }
    if (sum%2) return false
    return helper(nums,sum/2)
};

let helper = (nums,half,index=0,memo={}) => {
    if (half in memo && index in memo[half]) return memo[half][index]
    if (!memo[half]) memo[half] = {}
    if (half<=0 || index === nums.length) {
        memo[half][index] = (half === 0)
        return memo[half][index]
    } else {
        memo[half][index] = helper(nums,half,index+1,memo) || helper(nums,half-nums[index],index+1,memo)
        return memo[half][index]
    }
}



//tabulation
//time: O(len*half)
//space: O(half)
var canPartition2 = function(nums) {
    let sum = 0
    for (let num of nums) {
        sum += num
    }
    if (sum%2) return false
    let half = sum/2
    let dp = new Array(half+1).fill(false)
    dp[0] = true
    for (let num of nums) {
        for (let i=half; i>=0; i--) {
            if (i >= num) dp[i] = dp[i] || dp[i-num] 
        }
    }
    return dp[half]
};

let nums = [1,5,11,5]
console.log(canPartition2(nums))
