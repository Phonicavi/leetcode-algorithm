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
// recursive
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;

        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }

    ListNode* removeElements(ListNode* head, int val) {
        ListNode HD(0);
        HD.next = head;
        
        auto pre = &HD;
        auto tmp = HD.next;
        while (tmp) {
            if (tmp->val == val) {
                pre->next = tmp->next;
                delete tmp;
                tmp = pre->next;
            } else {
                pre = tmp;
                tmp = tmp->next;
            }
        }
        
        return HD.next;
    }
};