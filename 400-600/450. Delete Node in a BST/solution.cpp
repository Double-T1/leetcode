class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* p = new TreeNode(INT_MAX);
        p->left = root;
        search(p,key);
        return p->left;
    }
    
private:
    void search(TreeNode* node, int key) {
        if (!node) return;
        if (node->val == key) {
            if (node->right) {
                node->val = erase(node->right,true);
            } else if (node->left) {
                node->val = erase(node->left,false);
            } else {
                node->val = INT_MIN;
            }       
        } 
        else if (node->val > key) search(node->left,key);
        else search(node->right,key);
        
        checkLeft(node);
        checkRight(node);
    }
    
    int erase(TreeNode* node,bool toLeft) {
        if (!node) return INT_MIN;
        int x;
        if (toLeft)  {
            x = erase(node->left,toLeft);
        } else {
            x = erase(node->right,toLeft);
        }
        
        if (x == INT_MIN) {
            int temp = node->val;
            node->val = INT_MIN;
            return temp;
        } else {
            if (toLeft) {
                checkLeft(node);
            } else if (!toLeft) {
                checkRight(node);
            }
        }
        return x;
    }
    
    void checkLeft(TreeNode* node) {
        if (node->left && node->left->val == INT_MIN) {
            if (node->left->left) node->left = node->left->left;       
            else node->left = node->left->right;
        }
    }
    
    void checkRight(TreeNode* node) {
        if (node->right && node->right->val == INT_MIN) {
            if(node->right->right) node->right = node->right->right;
            else node->right = node->right->left;
        }
    }
};
