//substring are adjacent strings
///time: O(n)
//space: O(n)
var longestValidParentheses = function(s) {
    let max = 0
    let dp = []
    for (let i=0; i<s.length; i++) {
        if (s[i] === '(') {
            dp[i] = 0
        } else {
            //')' needs a left paren to fulfill
            //in search of a unregistered '('
            dp[i] = helper(s,dp,i-1)
            max = Math.max(max,dp[i])
        }
    }
    return max
};

//find the pairing '(' for ')' at i
//and return the total length ending at i
//if can't find, return 0
let helper = (s,dp,i) => {
    if (i<0) {
        return 0
    } else if (s[i] === '(') {
        let prev = i>1? dp[i-1] : 0
        return 2 + prev
    } else {
        if (dp[i]===0) return 0
        let x = helper(s,dp,i-dp[i])
        if (x>0) return x+dp[i]
        return 0
    }
}

let s = ""
console.log(longestValidParentheses(s))
