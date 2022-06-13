//sliding window
var findAnagrams = function(s, p) {
    let len = p.length
    let map = {}
    let count = 0
    for (let i=0; i<len; i++) {
        if (map[p[i]] === undefined) {
            map[p[i]] = 0
            count++
        }
        map[p[i]]++
    }

    let ans = []
    for (let i=0; i<s.length; i++) {
        if (map[s[i]] !== undefined) {
            map[s[i]]--
            count = caliberate(map,s[i],count,-1)
        }
        if (i>=len-1) { 
            if (count === 0) ans.push(i-len+1)
            if(map[s[i-len+1]] !== undefined) {
                map[s[i-len+1]]++
                count = caliberate(map,s[i-len+1],count,1)
            } 
        }
    }
    return ans
};

let caliberate = (map,char,count,k) => {
    if (map[char] === 0) {
        count--
    } else if (map[char] === k) {
        count++
    }
    return count
}

let  s = "abab", p = "ab"
console.log(findAnagrams(s,p))
