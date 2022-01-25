//union find
//if the incoming element matches with one of the elements in an union, then we skip to check in next component
//otherwise keep looking in this component
//time: O(n**2)
//TLE
var largestComponentSize = function(nums) {
    let parent = []
    for (let i=0; i<nums.length; i++) {
        parent[i] = i
        for (let j=0; j<i; j++) {
            if (find(parent,i) === find(parent,j)) continue
            if (gcd(nums[i],nums[j])>1) {
                union(parent,i,j)
            }
        }
    }

    let size = {}
    let max = 0
    for (let i=0; i<parent.length; i++) {
        let p = find(parent,i)
        if (size[p] === undefined) size[p] = 0
        size[p]++
        max = Math.max(size[p],max)
    }   
    return max
};

let union = (parent,a,b) => {
    let pa = find(parent,a)
    let pb = find(parent,b)
    if (pa === pb) return true 
    parent[pb] = pa
    return false
}

let find = (parent,a) => {
    if (parent[a] !== a) {
        parent[a] = find(parent,parent[a])
    }
    return parent[a]
}

//all inputs must be greater than 0
let gcd = (a,b) => {
    while (a!==b) {
        if (a>b) {
            a -= b 
        } else {
            b -= a
        }
    }
    return a
}

//time: O(n*sqrt(m)) m is the biggest number in the set
var largestComponentSize2 = function(nums) {
    let parent = []
    let n = nums.length
    for (let i=0; i<n; i++) {
        for (let j=2; j*j<=nums[i]; j++) {
            if (nums[i]%j===0) {
                union2(parent,nums[i],j)
                union2(parent,nums[i],nums[i]/j)
            }
        }
    }

    let map = {}
    let max = 0
    for (let i=0; i<n; i++) {
        max = Math.max(max,mp(map,find2(parent,nums[i])))
    }
    return max
};

let mp =(map,key) => {
    if (map[key] === undefined) map[key] = 0
    return ++map[key]
}

let union2 = (parent,a,b) => {
    let pa = find2(parent,a)
    let pb = find2(parent,b)
    if (pa === pb) return true 
    parent[pb] = pa
    return false
}

let find2 = (parent,a) => {
    if (parent[a] === undefined) parent[a] = a
    if (parent[a] !== a) {
        parent[a] = find2(parent,parent[a])
    }
    return parent[a]
}

//consider the prime numbers only
var largestComponentSize3 = function(nums) {
    let parent = []
    let n = nums.length
    for (let i=0; i<n; i++) {
        for (let j=2; j*j<=nums[i]; j++) {
            if (nums[i]%j===0) {
                union2(parent,nums[i],j)
                union2(parent,nums[i],nums[i]/j)
            }
        }
    }

    let map = {}
    let max = 0
    for (let i=0; i<n; i++) {
        max = Math.max(max,mp(map,find2(parent,nums[i])))
    }
    return max
};

let mp =(map,key) => {
    if (map[key] === undefined) map[key] = 0
    return ++map[key]
}

let union2 = (parent,a,b) => {
    let pa = find2(parent,a)
    let pb = find2(parent,b)
    if (pa === pb) return true 
    parent[pb] = pa
    return false
}

let find2 = (parent,a) => {
    if (parent[a] === undefined) parent[a] = a
    if (parent[a] !== a) {
        parent[a] = find2(parent,parent[a])
    }
    return parent[a]
}


let nums = [65,27,100,37,12,19,4,58,91,5]
console.log(largestComponentSize2(nums))
