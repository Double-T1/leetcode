//solution two is a lot better with optimized space usage
var removeDuplicates2 = function(s, k) {
    let stack = []
    stack = [[0,1]]
    for (let i=1; i<s.length; i++) {
        let last = stack[stack.length-1] 
        if (last !== undefined && s[last[0]] === s[i]) {
            last[1]++  
        } else {
            stack.push([i,1])
        } 

        if (last!==undefined && last[1] === k) {
            stack.pop()
        }
    }
    
    let str = ''
    for (let i=0; i<stack.length; i++) {
        for (let k=0; k<stack[i][1]; k++) {
            str += s[stack[i][0]]
        }
    }
    return str
};


var removeDuplicates = function(s, k) {
    let remain = new Set()
    let i=0
    while (i<s.length) {
        i = helper(s,k,remain,i)+1
    }
    let arr = [...remain]
    let str = ''
    for (let key of arr) {
        str = s[key] + str 
    }
    return str
};

//return the index of chars not removed
let helper = (s,k,remain,i) => {
    if (i === s.length) return i
    let current = s[i]
    let j = 1
    let next = i
    let arr = [i]
    while (j<k && next<s.length) {
        if (s[next+1] === current) {
            arr.push(next+1)
            j++
            next++
        } else {
            next = helper(s,k,remain,next+1)
        }
    }
    if (j !== k) {
        for (let ele of arr) {
            remain.add(ele)
        }
    }
    return next
}




let  s = "deeedbbcccbdaa", k = 3
console.log(removeDuplicates2(s,k))
