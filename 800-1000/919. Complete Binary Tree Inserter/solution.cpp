class CBTInserter {
private:
    queue<TreeNode*> qu;
    TreeNode* root;
    
public:
    CBTInserter(TreeNode* rt): root(rt) {
        qu.push(rt);
        while (true) {
            auto node = qu.front();
            if (node->left) {
                qu.push(node->left);
                if (node->right) {
                    qu.push(node->right);
                    qu.pop();
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }
    
    int insert(int val) {
        auto parent = qu.front();
        TreeNode* cur = new TreeNode(val);
        qu.push(cur);
        if (parent->left) {
            parent->right = cur;
            qu.pop();
        } else {
            parent->left = cur;
        }
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};
