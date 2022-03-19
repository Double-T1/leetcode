var FreqStack = function() {
    this.outerStack = []
    this.count = new Map()
    this.lastInner = -1 
};

/** 
 * @param {number} val
 * @return {void}
 */
FreqStack.prototype.push = function(val) {
    const outerStack = this.outerStack, count = this.count, lastInner = this.lastInner
    if (!count.has(val)) count.set(val,0)
    let t = count.get(val)
    if (outerStack[t] === undefined) outerStack[t] = []
    outerStack[t].push(val)
    count.set(val,t+1)
    this.lastInner = Math.max(lastInner,t)
};

/**
 * @return {number}
 */
FreqStack.prototype.pop = function() {
    const outerStack = this.outerStack, count = this.count, lastInner = this.lastInner
    let ans = outerStack[lastInner].pop()
    if (outerStack[lastInner].length === 0) this.lastInner--
    count.set(ans,count.get(ans)-1)
    return ans
};

/** 
 * Your FreqStack object will be instantiated and called as such:
 * var obj = new FreqStack()
 * obj.push(val)
 * var param_2 = obj.pop()
 */

/**
constraint: O(1) or O(logn)

*/
