var subsets = function(nums) {
    let arr = []
    backtrack(arr,nums)
    return arr
};

//all numbers are unique
let backtrack = (supArr,nums,i=0,subArr=[]) => {
    if (i === nums.length) {
        supArr.push([...subArr])
        return
    } else {
        //for each index, either we include or not include
        //1. not
        backtrack(supArr,nums,i+1,subArr)

        //2. include
        subArr.push(nums[i]) 
        backtrack(supArr,nums,i+1,subArr)
        subArr.pop()
        return
    }
}
