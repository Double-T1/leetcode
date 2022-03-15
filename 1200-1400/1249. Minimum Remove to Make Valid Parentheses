var minRemoveToMakeValid = function(s) {
    let str = '', leftCount = 0
    for (let i=0; i<s.length; i++) {
        if (/[a-z]/.test(s[i])) {
            str += s[i]
        } else {
            if(s[i] === '(') {
                str += s[i]
                leftCount++
            } else if (leftCount>0) {
                str += s[i]
                leftCount--
            }
        }
    }
    let rightCount = 0, ans = ''
    for (let i=str.length-1; i>=0; i--) {
        if (/[a-z]/.test(str[i])) {
            ans = str[i] + ans
        } else {
            if (str[i] === ')') {
                ans = str[i] + ans
                rightCount++
            } else if (rightCount>0) {
                ans = str[i] + ans
                rightCount--
            }
        }
    }
  return ans  
};
