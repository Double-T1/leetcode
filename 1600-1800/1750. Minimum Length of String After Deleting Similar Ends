var minimumLength = function(s) {
    let i=0, j=s.length-1
    while (s[j] === s[i] && j>i) { 
        while (s[i+1] === s[i] && j>i) i++
        while (s[j-1] === s[j] && j>i) j--
        if (j<=i) return 0
        i++, j--
    }
    return j-i+1
};
