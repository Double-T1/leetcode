//solution 3 is the best one

//O(n^2)
var maxEnvelopes = function(envelopes) {
    envelopes.sort((a,b) => {
        if (a[0] === b[0]) return a[1]-b[1]
        return a[0]-b[0]
    })
    let max = 0
    for (let i=0; i<envelopes.length; i++) {
        let [w,h] = envelopes[i]
        dp[i] = 1
        for (let j=0; j<i; j++) {
            if (w>=envelopes[j][0] && h>=envelopes[j][1]) {
                dp[i] = Math.max(dp[i],dp[j]+1)
            }
        }
        max = Math.max(max,dp[i])
    }
    return max
};

//O(nlogn)
//patient sort
//the crucial point is how to sort the original array => the goal is to reduce the dimensions to consider down to 1 dimension only
var maxEnvelopes2 = function(envelopes) {
    envelopes.sort((a,b) => {
        if (a[0] === b[0]) return b[1]-a[1]
        return a[0]-b[0]
    })
    //find the samllest number that doesn't suffice
    let binarySearch = (arr,left,right,w,h) => {
        while (left<right) {
            let mid = left + Math.floor((right-left))
            if (arr[mid][0]>=w || arr[mid][1]>=h) {
                right = mid
            } else {
                left = mid+1
            }
        }
        return right
    }
    let deck = []
    for (let i=0; i<envelopes.length; i++) {
        let j = binarySearch(deck,0,deck.length,envelopes[i][0],envelopes[i][1])
        if(j!==deck.length) deck[j] = envelopes[i]
        else deck.push(envelopes[i])         
    }
    return deck.length
};

//time: O(nlogn)
var maxEnvelopes3 = function(envelopes) {
    envelopes.sort((a,b) => {
        if (a[0] === b[0]) return b[1]-a[1]
        return a[0]-b[0]
    })
    //find the smallest number that doesn't suffice
    let binarySearch = (arr,left,right,target) => {
        while (left<right) {
            let mid = left + Math.floor((right-left)/2)
            if (arr[mid]>=target) {
                right = mid
            } else {
                left = mid+1
            }
        }
        return left
    }
    let deck = []
    for (let i=0; i<envelopes.length; i++) {
        let j = binarySearch(deck,0,deck.length,envelopes[i][1])
        if(j!==deck.length) deck[j] = envelopes[i][1]
        else deck.push(envelopes[i][1])        
    }
    return deck.length
};

let envelopes= [[5,4],[6,4],[6,7],[2,3]]
console.log(maxEnvelopes3(envelopes))
