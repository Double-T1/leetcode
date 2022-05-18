class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        queue<TreeNode*> qu;
        qu.push(root);
        int level = 0;
        while (!qu.empty()) {
            int size = qu.size();
            level++;
            while (size--) {
                auto node = qu.front(); qu.pop();
                if (!node->left && !node->right) return level;
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }
        }
        return level;
    }
};
