//brute force
//to max
//time: O((n^3)(2^n))
//potential TLE or OOM
//and since there are at most 500 input, bitmask doesn't work
var maxSatisfaction = function(satisfaction) {
    let ans = 0
    for (let n=0; n<=satisfaction.length; n++) {
        ans = Math.max(ans,helper(satisfaction,n))
    }
    return ans
};

let helper = (satisfaction,k,i=0,j=0,bitmask=0,memo=[]) => {
    if (j === k) return 0
    if (i === satisfaction.length) return Number.MIN_SAFE_INTEGER //when we reached the end but there are still k required dishes left 
    if (i in memo && bitmask in memo[i]) return memo[i][bitmask]
    if (memo[i] === undefined) memo[i] = []
    //for each element, to include or not include
    //not include
    let ans = helper(satisfaction,k,i+1,j,bitmask,memo)

    //include, the issue is the sequence for it to be served
    //i.e. which parameters[1:k] for it to times
    for (let m=1; m<=k; m++) {
        let bit = 1<<m
        if ((bitmask&bit)>0) continue
        ans = Math.max(ans,helper(satisfaction,k,i+1,j+1,bitmask|bit,memo)+satisfaction[i]*m)
    }
    memo[i][bitmask] = ans
    return memo[i][bitmask]
}

//bitmask actually doesn't work due to the input size of 500
//a little heuristic help => the biggest number alawys multiplies the biggest parameter
//the question now is what is the parameter?
var maxSatisfaction2 = function(satisfaction) {
    satisfaction.sort((a,b) => b-a)
    let ans = 0
    let current = 0
    let sum = 0
    for (let i=0; i<satisfaction.length; i++) {
        let num = satisfaction[i]
        current += num + sum
        if (num+sum<0) break
        sum += num
        ans = Math.max(ans,current)
    }
    return ans
};

let satisfaction = [-1,-8,0,5,-9]
console.log(maxSatisfaction2(satisfaction))
