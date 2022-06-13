var numOfSubarrays = function(arr, k, threshold) {
    let sum = 0
    for (let i=0; i<k-1; i++) {
        sum += arr[i]
    }

    let left = 0
    let count = 0
    for (let i=k-1; i<arr.length; i++) {
        sum += arr[i]
        if (sum>=k*threshold) count++
        sum -= arr[left]
        left++ 
    }
    return count
};
