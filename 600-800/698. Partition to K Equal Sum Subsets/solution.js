//brute force
//time: O(k**n)
var canPartitionKSubsets = function(nums, k) {
    let sum = nums.reduce((accu,ele) => accu+ele)
    if (sum%k !== 0) return false
    let target = sum/k
    let counter = new Array(k).fill(target)
    return helper(counter,nums)
};

let helper = (counter,nums,index=0,memo={}) => {
    if (index === nums.length) {
        for (let ele of counter) {
            if (ele !== 0) return false
        }
        return true
    } else {
        let res = false
        for (let i=index; i<counter.length; i++) {
            if (counter[i] === 0 || counter[i]<nums[index]) continue
            counter[i] -= nums[index]
            res |= helper(counter,nums,index+1,memo)
            counter[i] += nums[index]
            if (res) return true
        }
        return res
    }
}

//time: O(2**(k*n))
//super fucking slow
var canPartitionKSubsets2 = function(nums, k) {
    let sum = nums.reduce((accu,ele) => accu+ele)
    if (sum%k !== 0) return false
    let target = sum/k
    return helper2(nums,0,target,k)
};

let helper2 = (nums,current,target,k,visited=[],index=0) => {
    if (k === 1) {
        return true
    } else if (target === current) {
        return helper2(nums,0,target,k-1,visited,0)
    } else {
        for (let i=index; i<nums.length; i++) {
            if (visited[i] || current+nums[i]>target) continue
            visited[i] = true
            if (helper2(nums,current+nums[i],target,k,visited,i+1)) {
                return true
            } 
            visited = false
        }
        return false
    }
}

//much better time complexity
//time: O(n*(2**n)))
var canPartitionKSubsets3 = function(nums, k) {
    let sum = nums.reduce((accu,ele) => accu+ele)
    if (sum%k !== 0) return false
    let target = sum/k
    let upBound = 1<<nums.length
    let dp = []
    dp[0] = 0

    for (let mask=0; mask<upBound; mask++) {
        if (dp[0] === undefined) continue
        for (let i=0; i<nums.length; i++) {
            if ((mask&(1<<i))==0 && dp[mask] + nums[i]<=target) {
                dp[mask|(1<<i)] = (dp[mask]+nums[i])%target
            }
        }
    }
    return dp[upBound-1] === 0
};

let  nums = [1,2,3,4], k = 3
console.log(canPartitionKSubsets2(nums,k))
