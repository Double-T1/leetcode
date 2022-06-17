class Solution {
public:
    int minCameraCover(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int k = 0;
        while (!qu.empty()) {
            auto node = qu.front(); qu.pop();
            node->val = k++;
            if (node->left) qu.push(node->left);
            if (node->right) qu.push(node->right);
        }
        
        vector<vector<int>> dp(k,vector<int>(3,-1));
        return helper(dp,root,2);
    }
    
private:
    int helper(vector<vector<int>>& dp, TreeNode* node, int status) {
        if (!node) return status == 3 ? 1001 : 0;
        
        int val = node->val;
        if (dp[val][status-1]>-1) return dp[val][status-1];
        
        int ans;
        if (status == 1) {
            int dontPut = helper(dp,node->left,2) + helper(dp,node->right,2);
            int putHere = helper(dp,node->left,1) + helper(dp,node->right,1) + 1;
            ans = min(dontPut, putHere);
        } else if (status == 2) {
            int putHere = helper(dp,node->left,1) + helper(dp,node->right,1) + 1;
            int putLeft = helper(dp,node->left,3) + helper(dp,node->right,2);
            int putRight = helper(dp,node->left,2) + helper(dp,node->right,3);
            ans = min(putHere,min(putLeft,putRight));
        } else {
            ans = helper(dp,node->left,1) + helper(dp,node->right,1) + 1;
        }
        
        return dp[val][status-1] = ans;
    }
};

/*
for every node, it can be monitored by itself, its children or its parents

node: the node we're at
status: the three states of a node => whether it has a cam, and whether it is covered
1. it doesn't have a cam but is covered => no need for a cam
2. it doesn't have a cam and is not covered => can put a cam here, or put it at one of its children
3. it does have a cam and is covered => all its children are covered

x(node,status): for every node, given its status when arriving to it, return the minimum amount of cameras required for its represented subtree.
*/
