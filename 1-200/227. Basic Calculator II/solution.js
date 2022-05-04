var calculate = function(s) {
    let stack = []
    let numReg = /\d/
    let op = '+'
    let num = ''
    for (let i=0; i<=s.length; i++) {
        if(numReg.test(s[i])) {
            num = num + s[i]
        } else if (s[i] !== ' ' || i === s.length) {
            num = parseInt(num,10)
            switch (op) {
                case '+':
                    stack.push(num)
                    break
                case '-':
                    stack.push(-1*num)
                    break
                case '*':
                    stack.push(stack.pop()*num)
                    break
                case '/':
                    stack.push(Math.trunc(stack.pop()/num))
                    break
            }
            num = ''
            op = s[i]
        } 
    }

    let ans = 0
    while (stack.length) {
        ans += stack.shift()
    }
    return ans
};
