//adjust the algo according to the given data structure

//time: O(n)
//space: O(n)

//arbirarily malke children node =  1, 
//then add all the diff to the parent node, 
//and count the diff as steps
var distributeCoins = function(root) {
    if (!root) {
        return 0
    } else {
        return distributeCoins(root.left) + distributeCoins(root.right) + check(root,root.left) + check(root,root.right)
    }
};

let check = (node,children) => {
    let steps = 0
    if (children) {
        let val = children.val
        children.val = 1
        node.val += (val-1)
        steps += Math.abs(1-val) 
    }
    return steps
}


class Solution {
public:
    int distributeCoins(TreeNode* root) {
        if (!root) return 0;
        return distributeCoins(root->left) + distributeCoins(root->right) + check(root,root->left) + check(root,root->right);   
    }
    
private:
    int check(TreeNode* cur, TreeNode* child) {
        int steps = 0;
        if (child) {
            int val = child->val;
            child->val = 1;
            cur->val += val-1;
            steps += abs(val-1);
        }
        return steps;
    }
};
