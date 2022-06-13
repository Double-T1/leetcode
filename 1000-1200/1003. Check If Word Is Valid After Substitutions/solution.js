var isValid = function(s) {
    let stack = []
    for (let char of s) {
        if (char === 'a') {
            stack.push(char)
        } else if (char === 'b') {
            let prev = getLast(stack)
            if (prev==='a') {
                stack.pop()
                stack.push('ab')
            } else {
                return false
            } 
        } else {
            let prev = getLast(stack)
            if (prev === 'ab') {
                stack.pop()
            } else {
                return false
            }
        }
    }
    return stack.length === 0
};
    
let getLast = arr => {
    return arr[arr.length-1]
} 

/**
constraint: O(n) or O(nlogn)
observation: 
1. at least one substr will be 'abc' 

1. if a follows by b, they are from the same k
2. same with b and c
=> a can only follow a,b,c, b can only follow a or c
c can only follow b or c
*/
