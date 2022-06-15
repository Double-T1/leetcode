//time: O(nlogn + n*l*l)
//l being the length of each string
//space: O(n)
var longestStrChain = function(words) {
    words.sort((a,b) => a.length-b.length)
    let dist = []
    let max = 1
    dist[0] = 1
    for (let i=1; i<words.length; i++) {
        let l = words[i].length
        dist[i] = 1
        for (let j=i-1; j>=0 && words[j].length >= l-1; j--) {
            if (compare(words[j],words[i])) {
                dist[i] = Math.max(dist[i],dist[j]+1)
            }
        }
        max = Math.max(max,dist[i])
    }
    return max
};

//a should be able to insert one char to become b
let compare = (a,b) => {
    if (a.length === b.length) return false
    let i=0, j=0
    let once = false 
    while (j<b.length) {
        if (a[i] === b[j]) {
            i++
            j++
        } else {
            if (!once) {
                j++
                once = true
            } else {
                return false
            }
        }
    }   
    return i===a.length && j===b.length && once
}
