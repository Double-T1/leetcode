//time: O(n*(log10^9))
var minimumSize = function(nums, maxOperations) {
    //find the minimum penalty, which is 
    let left = 0, right = 10**9+1
    while (left<right) {
        let mid = left + Math.floor((right-left)/2)
        if (check(nums,mid)<=maxOperations) {
            right = mid
        } else {
            left = mid+1
        }
    }
    return left
};
    
let check = (nums,x) => {
    return nums.reduce((accu,ele) => accu + Math.ceil(ele/x)-1,0)
}
