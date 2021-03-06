//count the maximum pairs equal to k
//time: O(nlogn)
//space: O(1)
var maxOperations = function(nums, k) {
    nums.sort((a,b) => a-b)
    let left = 0
    let right = nums.length-1
    let count = 0
    while (left<right) {
        let val = nums[left]+nums[right]
        if (val===k) {
            count++
            left++
            right--
        } else if (val<k) {
            left++
        } else {
            right--
        }
    }
    return count
};



//time space trade-off
//tme: O(n)
//space: O(n)
var maxOperations2 = function(nums, k) {
    let map = new Map()
    let count = 0
    for (let i=0; i<nums.length; i++) {
        let val = k-nums[i]
        if (map.has(val) && map.get(val)>0) {
            count++
            let a = map.get(val)
            map.set(val,a-1)
        } else {
            if (!map.has(nums[i])) map.set(nums[i],0) 
            let a = map.get(nums[i])
            map.set(nums[i],a+1)
        }
    }
    return count
};


let  nums = [3,1,3,4,3], k = 6
console.log(maxOperations2(nums,k))
