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
        if (!root) return nullptr;
        connect(goNext(root));
        return root;
    }
    
private:   
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
public:
    Node* connect(Node* root) {
        auto leftMostParent = root;
        Node* prev;
        while (leftMostParent) {
            auto parent = leftMostParent;
            prev = nullptr;
            leftMostParent = nullptr;
            while (parent) {                
                if (parent->left) {
                    if (prev) prev->next = parent->left;
                    else leftMostParent = parent->left;
                        
                    if (parent->right) {
                        parent->left->next = parent->right;
                        prev = parent->right;
                    } else {
                        prev = parent->left;
                    }
                } else if (parent->right) {
                    if (prev) prev->next = parent->right;
                    else leftMostParent = parent->right;
                    
                    prev = parent->right;
                }
                
                parent = parent->next;
            }
        }
        
        return root;
    }
};

