var maxPower = function(s) {
    let prev = s[0]
    let maxLen = 1
    let currentLen = 1
    for (let i=1; i<s.length;i++){
        if(s[i]=== prev) {
            currentLen++
        } else {
            currentLen = 1
            prev = s[i]
        }
        maxLen = Math.max(maxLen,currentLen)
    }
    return maxLen
};
