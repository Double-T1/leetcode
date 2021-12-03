var productExceptSelf = function(nums) {
    let res = new Array(nums.length)
    res[0] = nums[0]

    for (let i=1 ; i<nums.length; i++) {
        res[i] = res[i-1]*nums[i]
    }

    res[res.length-1] = res[res.length-2]
    for (let i=res.length-2; i>=1; i--) {
        res[i] = res[i-1]*nums[i+1]
        nums[i] *= nums[i+1] 
    } 
    res[0] = nums[1]

    return res
};
