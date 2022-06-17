class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        return helper(root,false,false);
    }
    
private:
    int helper(TreeNode* node, bool evenGrand, bool evenParent) {
        if (!node) return 0;
        
        bool evenCur = node->val%2 == 0;
        int ans = helper(node->left,evenParent,evenCur) + helper(node->right,evenParent,evenCur); 
        if(evenGrand) ans += node->val;
        return ans;
    }  
};
