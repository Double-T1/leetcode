var minCameraCover = function(root) {
    return helper(root)
};

//recursion
//lights that only cover itself => 1 (can move up to its parent)
//lights that cover itself and its children => 2 (can't move)
//spots covered by its children => 3
let helper = (root) => {
    if (!root) {
        return 0
    } else {
        let res = helper(root.left) + helper(root.right)
        
        if (!root.left && !root.right) root.val = 1
        check(root,root.left)
        check(root,root.right)
        if (root.left && root.left.val === 1 && root.right && root.right.val === 1) res--
        if (root.val === 1) res++
        return res
    }
}


let check = (root,children) => {
    if (children) {
        let childVal = children.val
        let currentVal = root.val

        if (childVal === 3) root.val = 1
        if (currentVal === 3 || childVal === 2) root.val = 3
        if (childVal === 1 || currentVal === 2) root.val = 2
    }
    return
}
