class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int ans= 0;
        while(!qu.empty()) {
            int size = qu.size();
            ans = 0;
            while(size--) {
                auto node = qu.front(); qu.pop();
                ans += node->val;
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }
        }
        return ans;
    }
};
