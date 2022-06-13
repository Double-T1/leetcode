//return the depth of the deepest leaves and the LCA of them
//the most intuitive way
var lcaDeepestLeaves = function(root) {
    let ans = helper(root)
    return ans[1]
};

//depth is the depth of its previous node
let helper = (node,depth=0) => {
    if (!node) {
        return [depth-1,null]
    } else {
        let [leftDepth,lcaLeft] = helper(node.left,depth+1)
        let [rightDepth,lcaRight] = helper(node.right,depth+1)
        if (leftDepth === rightDepth) {
            return [leftDepth,node]
        } else if (leftDepth>rightDepth) {
            return [leftDepth,lcaLeft]
        } else {
            return [rightDepth,lcaRight]
        }
    }
}

// a space optimized way
//practically speaking, the runtime will be improved siginificantly as well
var lcaDeepestLeaves = function(root) {
    let ans = [null,0]
    helper2(root,ans)
    return ans[0]
};

//depth is the depth of its previous node
let helper2 = (node,ans,depth=0) => {
    ans[1] = Math.max(ans[1],depth) //to record the deepest depth
    if (!node) {
        return depth
    } else {
        let leftDepth = helper2(node.left,ans,depth+1)
        let rightDepth = helper2(node.right,ans,depth+1)
        if (leftDepth === rightDepth && leftDepth===ans[1]) {
            ans[0] = node
        } 
        return Math.max(leftDepth,rightDepth)
    }
}
