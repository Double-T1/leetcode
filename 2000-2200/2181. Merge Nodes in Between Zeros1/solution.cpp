class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prev = head;
        int sum = 0;
        for (auto p = head->next; p != nullptr ;p = p->next) {
            if (p->val == 0) {
                prev->next = p;
                prev = p;
                p->val = sum;
                sum = 0;
            } else {
                sum += p->val;
            }
        }
        return head->next;
    }
};
