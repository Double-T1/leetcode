class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto fast = head;
        auto slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return fast->next? slow->next : slow;
    }
};
