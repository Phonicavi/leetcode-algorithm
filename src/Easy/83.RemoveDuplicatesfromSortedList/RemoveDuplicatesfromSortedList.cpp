/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head||!(head->next)) return head;
        auto pre = head;
        while (pre&&pre->next) {
            auto tmp = pre->next;
            if (tmp->val == pre->val) {
                pre->next = tmp->next;
                delete tmp;
            } else { // 值相等的时候不移动pre 直到遇到新的值才前进pre
                pre = pre->next;
            }
        }
        return head;
    }
};