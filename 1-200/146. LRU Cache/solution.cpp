class LRUCache {
private:
    struct ListNode {
        int key;
        int val;
        ListNode* next;
        ListNode* prev;
        
        ListNode(int k=-1, int v=-1): key(k), val(v), next(nullptr), prev(nullptr) {}
    };
    
    unordered_map<int, ListNode*> m;
    ListNode *head, *last;
    
public:
    LRUCache(int capacity) {
        head = new ListNode();
        auto cur = head;
        while ((capacity--)>=0) {
            cur->next = new ListNode();
            cur->next->prev = cur;
            cur = cur->next;
        }  
        last = cur;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1;
        removeNode(it->second);
        insertHead(it->second);
        
        //print();
        return head->next->val;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it == m.end()) {
            m[key] = new ListNode(key,value);
            insertHead(m[key]);

            auto t = last->prev;
            removeNode(t);
            m.erase(t->key);
            delete t;
        } else {
            m[key]->val = value;
            removeNode(m[key]);
            insertHead(m[key]);
        }
        //print();
    }
    
private:
    void removeNode(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void insertHead(ListNode* node) {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    
    void print() {
        for (auto node=head; node; node=node->next) {
            cout << node->key << ":" << node->val << " ";
        }
        cout << endl;
    }
};
