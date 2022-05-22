var countSubstrings = function(s) {
    let accu = 0
    for (let i=0; i<s.length; i++) {
        accu += expandAroundCenter(s,i,i) + expandAroundCenter(s,i,i+1)
    }
    return accu
};

let expandAroundCenter = (s,left,right) => {
    let count = 0
    while (left>=0 && right<s.length && s[left] === s[right]) {
        left--
        right++
        count++
    }
    return count
}
