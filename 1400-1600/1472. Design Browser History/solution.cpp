class BrowserHistory {
private:
    struct ListNode {
        string url;
        ListNode* next;
        ListNode* prev;
        
        ListNode(string& u): url(u), next(nullptr), prev(nullptr) {
        }
        
        void clear() {
            if(next) next->clear();
            delete next;
            next = nullptr;
        }
    };
    
    ListNode* home;
    ListNode* cur;
    
public:
    BrowserHistory(string homepage) {
        cur = new ListNode(homepage);
        home = cur;
    }
    
    ~BrowserHistory() {
        home->clear();
        delete home;
    }
    
    void visit(string url) {
        cur->clear();
        
        cur->next = new ListNode(url);
        cur->next->prev = cur;
        cur = cur->next;
    }
    
    string back(int steps) {
        while (steps-- && cur->prev) {
            cur = cur->prev;
        }
        return cur->url;
    }
    
    string forward(int steps) {
        while (steps-- && cur->next) {
            cur = cur->next;
        }
        return cur->url;
    }
};
