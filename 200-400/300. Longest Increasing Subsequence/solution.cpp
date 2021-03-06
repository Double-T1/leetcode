//C++
//O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ref;
        for (int num: nums) {
            auto ptr = lower_bound(ref.begin(),ref.end(),num);
            if (ptr == ref.end()) ref.push_back(num);
            else *ptr = num;
        }
        return ref.size();
    }
};


//time: O(n^2)
var lengthOfLIS = function(nums) {
    let dp = []
    let max = 0
    for (let i=0; i<nums.length; i++) {
        dp[i] = 1
        for (let j=0; j<i; j++) {
            if (nums[j]<nums[i]) {
                dp[i] = Math.max(dp[i],dp[j]+1)
            }
        }
        max = Math.max(dp[i],max)
    }
    return max
};

//time: O(nlogn)
var lengthOfLIS = function(nums) {
    //find the smallest number that is greater than or equal to target
    let binarySearch = (arr,left,right,target) => {
        while (left<right) {
            let mid = left + Math.floor((right-left)/2)
            if (arr[mid]>=target) {
                right = mid 
            } else {
                left = mid+1
            }
        }
        return left
    }
    
    let deck = []
    for (let i=0; i<nums.length; i++) {
        let j = binarySearch(deck,0,deck.length,nums[i])
        if (j !== deck.length) deck[j] = nums[i]
        else deck.push(nums[i])
    }
    return deck.length
};

//time: O(n^2)
var lengthOfLIS = function(nums) {
    nums.unshift(Number.MIN_SAFE_INTEGER)
    return helper(nums)-1
};

let helper = (nums,i=0,memo=[]) => {
    if (i in memo) return memo[i]

    let ans = 0
    for (let j=i+1; j<nums.length; j++) {
        if (nums[j]>nums[i]) {
            ans = Math.max(ans,helper(nums,j,memo))
        }
    }
    memo[i] = ans+1
    return memo[i]
}
