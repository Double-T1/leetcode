//time: O(n)
//space: O(n)
//a great example where bottom-up is so much faster than top-down

var minSwap = function(nums1, nums2) {
    return helper([nums1,nums2])
};
//guaranteed to have an successful swap => but some branches could be not fulfilling
let helper = (nums,i=0,prev=0,memo=[]) => {
    if (i===nums[0].length) memo[i][prev] = 0
    if (i in memo && prev in memo[i]) return memo[i][prev]
    if (memo[i] === undefined) memo[i] = []
    //at each current, we can decide either to swap or not to swap
    //not to swap
    let ans = Number.MAX_SAFE_INTEGER, prev2 = (prev+1)%2
    if (i===0 || nums[0][i]>nums[prev][i-1] && nums[1][i]>nums[prev2][i-1]) {
        ans = Math.min(ans,helper(nums,i+1,0,memo))            
    }

    //swap => certify that post-swap, s[:i] is still an increasing sequence
    if (i===0 || nums[0][i]>nums[prev2][i-1] && nums[1][i]>nums[prev][i-1]) {
        ans = Math.min(ans,helper(nums,i+1,1,memo)+1)    
    }
    memo[i][prev] = ans

    return memo[i][prev]
}

var minSwap2 = function(nums1, nums2) {
    let dp = [0,0], dup=[]
    let nums = [nums1,nums2]
    for (let i=nums1.length-1; i>=0; i--) {
        dup = [Number.MAX_SAFE_INTEGER,Number.MAX_SAFE_INTEGER]
        for (let prev=0; prev<2; prev++) {
            let prev2 = (prev+1)%2
            if (i===0 || nums[0][i]>nums[prev][i-1] && nums[1][i]>nums[prev2][i-1]) {
                dup[prev] = Math.min(dup[prev],dp[0])            
            }

            //swap => certify that post-swap, s[:i] is still an increasing sequence
            if (i===0 || nums[0][i]>nums[prev2][i-1] && nums[1][i]>nums[prev][i-1]) {
                dup[prev] = Math.min(dup[prev],dp[1]+1)    
            }
        }
        dp = dup
    }
    return dp[0]
};


var minSwap3 = function(nums1, nums2) {
    let dp = [0,0], dup=[]
    let nums = [nums1,nums2]
    for (let i=nums1.length-1; i>=1; i--) {
        dup = [Number.MAX_SAFE_INTEGER,Number.MAX_SAFE_INTEGER]
        for (let prev=0; prev<2; prev++) {
            let prev2 = (prev+1)%2
            if (nums[0][i]>nums[prev][i-1] && nums[1][i]>nums[prev2][i-1]) {
                dup[prev] = dp[0]            
            }

            //swap => certify that post-swap, s[:i] is still an increasing sequence
            if (nums[0][i]>nums[prev2][i-1] && nums[1][i]>nums[prev][i-1]) {
                dup[prev] = Math.min(dup[prev],dp[1]+1)    
            }
        }
        dp = dup
    }
    return Math.min(dp[0],dp[1]+1)
};

let nums1 = [48,49,46,47,50,52], nums2 = [44,45,50,55,56,57]
console.log(minSwap2(nums1,nums2))
