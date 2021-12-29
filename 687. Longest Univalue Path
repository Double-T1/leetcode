var longestUnivaluePath = function(root) {
    let max = [0]
    helper(root,max)
    return max[0]
};

let helper = (node,max) => {
    if (!node) return 0 

    let left = helper(node.left,max)
    let right = helper(node.right,max)
    
    let leftLen = 0
    let rightLen = 0
    if (node.left && node.left.val === node.val) {
        leftLen = left+1
    }
    if (node.right && node.right.val === node.val) {
        rightLen = right+1
    }
    max[0] = Math.max(max[0],leftLen+rightLen)
    return Math.max(leftLen,rightLen)
}
