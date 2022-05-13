//bfs
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node*> qu;
        qu.push(root); 
        Node* prev;
        while(!qu.empty()) {
            int size = qu.size();
            while(size--) {
                auto node = qu.front(); qu.pop();
                if(prev) prev->next = node;
                prev = node;
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }
            prev = nullptr;
        }
        return root;
    }
};

//dfs + recursion
class Solution {
public:
    Node* connect(Node* root) {
        goDown(root);
        return root;
    }
    
private:
    void goDown(Node*root) {
        if (!root) return;
        goNext(root);
        
        while (!root->left && !root->right && root->next) root =  root->next;
        
        if (root->left) goDown(root->left);
        else if (root->right) goDown(root->right);
    }
    
    
    Node* goNext(Node* parent) {
        if (!parent) return nullptr;
        
        if (parent->left) {
            if (parent->right) {
                parent->left->next = parent->right;
                parent->right->next = goNext(parent->next);
            } else {
                parent->left->next = goNext(parent->next);
            }
            return parent->left;
        } else if (parent->right) {
            parent->right->next = goNext(parent->next);
            return parent->right;
        } 
        return goNext(parent->next);
    }
};

/*
link the childrens at the parent level
traverse next, once at the end, back to the leftest that can go down (either left or right)
*/

//iteration
//space: O(1)
//same time: O(n)
class Solution {
public:
    Node* connect(Node* root) {
        auto leftMostParent = root;
        Node* prev;
        while (leftMostParent) {
            auto parent = leftMostParent;
            prev = nullptr;
            while (parent) {                
                if (parent->left) {
                    if (prev) prev->next = parent->left;
                    if (parent->right) {
                        parent->left->next = parent->right;
                        prev = parent->right;
                    } else {
                        prev = parent->left;
                    }
                } else if (parent->right) {
                    if (prev) prev->next = parent->right;
                    prev = parent->right;
                }
                
                parent = parent->next;
            }
            
            while(!leftMostParent->left && !leftMostParent->right && leftMostParent->next) 
                leftMostParent = leftMostParent->next;
            
            if (leftMostParent->left) leftMostParent= leftMostParent->left;
            else leftMostParent = leftMostParent->right;
        }
        
        return root;
    }
};
