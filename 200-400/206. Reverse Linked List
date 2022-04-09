class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        auto start = head;
        for (auto node = head; node && node->next;) {
            auto next = node->next;
            node->next = next->next;
            next->next = start;
            start = next;
        }
        return start;
    }
};

//recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head->next)) return head;
        
        auto node = reverseList(head->next);
        head->next->next = head; 
        head->next = nullptr;
        return node;
    }
};
