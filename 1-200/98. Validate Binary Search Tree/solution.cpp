class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> vector;
        inorder(vector,root);
        
        for (int i=1; i<vector.size(); i++) {
            if (vector[i]<=vector[i-1]) return false;
        }
        return true;
    }
    
    void inorder(vector<int>& vector, TreeNode* node) {
        if (node) {
            inorder(vector,node->left);
            vector.push_back(node->val);
            inorder(vector,node->right);
        } 
    }
};

//solution 2 
//to avoid the edge case where the node value is INT_MAX
//we have to use LONG to bound
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        auto vec = helper(root);
        return vec[0] != LONG_MIN && vec[1] != LONG_MAX;
    }
    
    vector<long> helper(TreeNode* node) {
        if (!node) return {LONG_MAX,LONG_MIN};
        auto left = helper(node->left);
        auto right = helper(node->right);
        
        long val = (long)node->val;
        if (val>left[1] && val<right[0]) {
            return {min(left[0],val),max(val,right[1])};
        } else {
            return {LONG_MIN,LONG_MAX};
        }
    }
};
