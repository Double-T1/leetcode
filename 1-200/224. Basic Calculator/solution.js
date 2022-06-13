var calculate = function(s) {
    let stack = ['+']
    let op = '+'
    let num = ''
    let ans = 0
    for (let i=0; i<=s.length; i++) {
        if (/\d/.test(s[i])) {
            num = num + s[i]
        } else if (s[i] === '(') {
            stack.push(op)
        } else if (s[i] === ')') {
            stack.pop()
        } else if (s[i] !== ' ') {
            if (num !== '') {
                if (op === '+') {
                    ans += parseInt(num)
                } else {
                    ans -= parseInt(num)
                }
                num = ''
            }
            
            let hiOp = peek(stack)
            if (hiOp === '+') {
                op = s[i]
            } else {
                op = s[i] === '+'? '-' : '+'
            }
        }
    }
    return ans
};


let peek = (stack) => {
    return stack[stack.length-1]
}
