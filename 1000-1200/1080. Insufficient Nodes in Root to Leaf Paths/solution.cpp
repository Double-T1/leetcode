class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return helper(root,limit,0)<limit ? nullptr : root;
    }
    
private:
    int helper(TreeNode* node, int limit, int parentRoute) {
        int curRoute = node->val + parentRoute;
        int leftRoute = node->left? helper(node->left,limit,curRoute) : INT_MIN;
        int rightRoute = node->right? helper(node->right,limit,curRoute) : INT_MIN;
        
        if (leftRoute<limit) node->left = nullptr;
        if (rightRoute<limit) node->right = nullptr;
        
        int x = max(leftRoute,rightRoute);
        return x == INT_MIN ? curRoute : x;
    }
};
