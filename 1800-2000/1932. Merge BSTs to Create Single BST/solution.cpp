//solution 1 and solution 2 are basically the same idea
//1 is with dfs and 2 is with bfs
//however, 1 is much cleaner and simpler in terms of code
//solution 1
class Solution {
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int,TreeNode*> roots;
        unordered_map<int,int> count;
        for (auto node: trees) {
            if (!toRegister(node,roots)) return nullptr;
            count[node->val]++;
            if (node->left) count[node->left->val]++;
            if (node->right) count[node->right->val]++;
        }
        
        TreeNode* root = nullptr;
        for (auto&[val,num] : count) {
            if (num == 1 && roots.count(val)) root = roots[val];
        }
        if (root == nullptr) return nullptr;
        
        roots.erase(root->val);
        return merge(roots,root) && roots.empty() ? root : nullptr; 
    }
    
private:
    bool merge(unordered_map<int,TreeNode*>& m, TreeNode* r, int low=INT_MIN, int up=INT_MAX) {
        if (r == nullptr) return true;
        if (r->val <= low || r->val >= up) return false;
        //both nullptr
        if (r->left == r->right) {
            auto it = m.find(r->val);
            if (it != m.end() && it->second != r) {
                r->left = it->second->left;
                r->right = it->second->right;
                m.erase(r->val);
            }
        }
        return merge(m,r->left,low,r->val) && merge(m,r->right,r->val,up);
    }
    
    bool toRegister(TreeNode* node, unordered_map<int,TreeNode*>& map) {
        if (map.find(node->val) != map.end()) return false;
        map[node->val] = node;
        return true;
    }
};


//solution 2
class Solution {
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int,TreeNode*> roots, leaves;
        for (auto node: trees) {
            if (!toRegister(node,roots)) return nullptr;
            if (node->left && !toRegister(node->left,leaves)) return nullptr;
            if (node->right && !toRegister(node->right,leaves)) return nullptr;
        }
        
        TreeNode* root = nullptr;
        for (auto&[v,node] : roots) {
            if (leaves.find(v) == leaves.end()) {
                if (root != nullptr) return nullptr;
                else root = node;
            }
        }
        if (root == nullptr) return nullptr;
        
        queue<tuple<TreeNode*,int,int>> qu;
        qu.emplace(root,INT_MIN,INT_MAX);
        roots.erase(root->val);
        while (!qu.empty()) {
            auto[node,lower,upper] = qu.front(); qu.pop();
            if (node->left && roots.count(node->left->val)) {
                if (!isValid(roots[node->left->val],lower,node->val)) return nullptr;
                node->left = roots[node->left->val];
                qu.emplace(node->left,lower,node->val);
                roots.erase(node->left->val);
            }
            
            if (node->right && roots.count(node->right->val)) {
                if (!isValid(roots[node->right->val],node->val,upper)) return nullptr;
                node->right = roots[node->right->val];
                qu.emplace(node->right,node->val,upper);
                roots.erase(node->right->val);
            }
        }
        
        return roots.empty()? root: nullptr;
    }
    
private:
    bool toRegister(TreeNode* node, unordered_map<int,TreeNode*>& map) {
        if (map.find(node->val) != map.end()) return false;
        map[node->val] = node;
        return true;
    }
    
    bool isValid(TreeNode* r, int low, int up) {
        if ((r->left && r->left->val<=low) || (!r->left && r->val<=low)) return false;
        if ((r->right && r->right->val>=up) || (!r->right && r->val>=up)) return false;
        return true;
    }
};

/*
constraint: O(n) or O(nlogn)
guaranteed to be valid => at the end there will be one huge BST 
=> 
1. no leaves share the same value
2. the eventual root node doesn't match any leaves 
3. all the other leaves and roots have a one-on-one value

if any of the above doesn't suffice, we can not form a valid BST

instructions:
1. find the only root with no matching leaves
=> record all the leaves and roots first

2. while adding, check if newly added tree fits the base tree
=> the max and min of new tree is contained by the uppper and lower of the base tree
=> set a hashmap for the leaves to quicly find the upper and lower.



*/
