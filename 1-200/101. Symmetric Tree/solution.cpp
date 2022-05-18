class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> l, r;
        if (notValid(root->left,root->right,l,r)) return false;
        
        while (!l.empty() && !r.empty()) {
            auto left = l.front(); l.pop();
            auto right = r.front(); r.pop();
            if (left->val != right->val) return false;
            
            if (notValid(left->left,right->right,l,r)) return false;
            if (notValid(left->right,right->left,l,r)) return false;
        }
        
        return l.empty() && r.empty();
    }
    
private:
    bool notValid (TreeNode* a, TreeNode* b,queue<TreeNode*>& l, queue<TreeNode*>& r) {
        if ((bool)a^(bool)b == 0) {
            if (a) {
                l.push(a);
                r.push(b);
            }
            return false;
        } else {
            return true;
        }
    }
};
