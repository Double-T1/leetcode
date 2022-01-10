var minDistance = function(word1, word2) {
    return helper(word1,word2)
};

let helper = (word1,word2,i1=0,i2=0,memo={}) => {
    if (memo[i1] === undefined || memo[i1][i2] === undefined) {
        if (memo[i1] === undefined) memo[i1] = {}
        
        if (i1 === word1.length || i2 === word2.length) {
            memo[i1][i2] = word1.length-i1 + word2.length-i2
        } else if  (word1[i1] === word2[i2]) {
            memo[i1][i2] = helper(word1,word2,i1+1,i2+1)
        } else {
            memo[i1][i2] = Math.min(helper(word1,word2,i1+1,i2),helper(word1,word2,i1,i2+1)) + 1
        }
    } 
    return memo[i1][i2]
}

let word1 = "sea", word2 = "eat"
console.log(minDistance(word1,word2))
