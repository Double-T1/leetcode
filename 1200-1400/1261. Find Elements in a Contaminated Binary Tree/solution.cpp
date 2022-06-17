class FindElements {
private:
    unordered_set<int> hashset;
    
public:
    FindElements(TreeNode* root) {
        helper(root);
    }
    
    bool find(int target) {
        return hashset.count(target);
    }
    
private:
    void helper(TreeNode* node, int x=0) {
        if (!node) return;
        
        hashset.insert(x);
        helper(node->left,2*x+1);
        helper(node->right,2*x+2);
    }
};
