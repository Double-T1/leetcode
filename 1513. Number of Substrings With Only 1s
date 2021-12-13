var numSub = function(s) {
    let total = 0
    let prev = '0'
    let current = 0
    for (let i=0; i<s.length; i++) {
        if (s[i] === '1') {
            if (prev === '1') {
                current ++
            } else {
                current = 1
                prev = '1'   
            }
            total += current
            total = total%(10**9+7)
        } else {
            prev = '0'
        }
    }
    return total
};
