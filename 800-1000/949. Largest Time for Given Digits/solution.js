var largestTimeFromDigits = function(arr) {
    //try all possibility
    let time = []
    time = exhuast(arr,0,time)
    return stringify(time)
}

let stringify = (time) => {
    if (time.length == 0) return ''
    return time[0].toString() + time[1].toString() + ':' + time[2].toString() + time[3].toString()
}

let exhuast = (arr,i,time,subArr=[],visited=[]) => {
    if (i === arr.length) {
        if (isValid(subArr)) time = [...compare(time,subArr)]
        return time
    } else {
        for (let j=0; j<arr.length; j++) {
            if (visited[j]) continue
            visited[j] = true
            subArr.push(arr[j])
            time = exhuast(arr,i+1,time,subArr,visited)
            visited[j] = false
            subArr.pop()
        }
        return time
    }
}

let isValid = (arr) => {
    //for HH
    let h = arr[0]*10 + arr[1]
    if (h>23) return false

    //for MM
    let m = arr[2]*10 + arr[3]
    if (m>59) return false
    return true
}


let compare = (a,b) => {
    if (a.length === 0) return b

    for (let i=0; i<a.length; i++) {
        if (a[i]>b[i]) {
            return a
        } else if (a[i]<b[i]) {
            return b
        }
    }
    return a
}


let arr = [2,0,6,6]
console.log(largestTimeFromDigits(arr))
