var isIsomorphic = function(s, t) {
    if (s.length !== t.length) return false
    let map = new Map(), set = new Set()
    for (let i=0; i<s.length; i++) {
        let x = map.has(s[i]), y = set.has(t[i])
        if (x || y) {
           if (x && y && map.get(s[i])===t[i]) continue
            return false
        } else {
            map.set(s[i],t[i])
            set.add(t[i])
        }
    }
    return true
};
