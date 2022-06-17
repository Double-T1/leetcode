class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        return helper(root).second;
    }
    
private:
    pair<int,int> helper(TreeNode* node) {
        if (!node) return {0,0};
        
        auto[leftCount,leftValid] = helper(node->left);
        auto[rightCount,rightValid] = helper(node->right);
        
        int val = node->val;
        if (node->left) node->val += node->left->val;
        if (node->right) node->val += node->right->val;
        
        int average = node->val/(leftCount+rightCount+1);
        return {leftCount+rightCount+1,leftValid+rightValid+(average == val)};
    }
};
