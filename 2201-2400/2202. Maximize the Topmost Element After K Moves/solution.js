var maximumTop = function(nums, k) {
    if (nums.length === 1) return k%2 === 0 ? nums[0] : -1
    let limit = Math.min(nums.length-1,k), max = -1
    for (let i=0; i<=limit; i++) {
        if(i!==k-1) max = Math.max(max,nums[i])
    }
    return max
};



/**
constraint: n or nlogn, k<=10^9 cannot simulate
In case it is not possible to obtain a non-empty pile after k moves, return -1
observation: (0-indexed)
1. only the topmost/leftmost k+1(0-k) elements may be the top => only consider them
2. if the element is the kth(indexed k-1) element, it cannot be the topmost element
3. in general, if there if only one move left for the current topmost, it cannot be the topmost



k>n
k=0



filler
*/
