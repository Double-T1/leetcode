class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<vector<int>> ans;
        if (!root) return ans;
        queue.push(root);
        while (queue.size()) {
            int size = queue.size();
            vector<int> sub;
            while (size) {
                size--;
                
                auto node = queue.front();
                queue.pop();
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
                sub.push_back(node->val);
            }
            ans.push_back(sub);
        }
        return ans;
    }
};
