var accountsMerge = function(accounts) {
    let emailDict = {} //map the emails to relative group
    let parents = new Array(accounts.length)
    for (let i=0; i<parents.length; i++) {
        parents[i] = i
    }
    
    for (let k=0; k<accounts.length; k++) {
        let list = accounts[k]
        for (let i=1; i<list.length; i++) {
            let email = list[i]
            if (emailDict[email] !== undefined) {
                union(parents,emailDict[email],k)
            } else {
                emailDict[email] = k 
            }
        }
    }
    
    let ans = []
    let indexMap = {}
    for (let [email,index] of Object.entries(emailDict)) {
        let p = find(parents,index)
        if (indexMap[p] === undefined) {
            ans.push([accounts[p][0]])
            indexMap[p] = ans.length-1
        }
        ans[indexMap[p]].push(email)
    }

    for (let arr of ans) {
        let name = arr.shift()
        arr.sort()
        arr.unshift(name)
    }

    return ans
};

let union = (parents,x,y) => {
    let px = find(parents,x)
    let py = find(parents,y)
    parents[py] = px
    return
}

let find = (parents,x) => {
    if (x !== parents[x]) {
        parents[x] = find(parents,parents[x])
    }
    return parents[x]
}

let accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
console.log(accountsMerge(accounts))
