class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> qu;
        qu.push(root);
        vector<int> sub;
        while (!qu.empty()) {
            int size = qu.size();
            sub.clear();
            while (size) {
                size--;
                auto node = qu.front(); qu.pop();
                sub.push_back(node->val);
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }
            ans.push_back(sub);
        }
        return ans;
    }
};
