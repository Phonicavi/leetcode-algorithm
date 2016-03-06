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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* HD = new ListNode(0);
        HD->next = head;
        auto nil = head;
        for (int i=0; i<n; ++i) nil = nil->next;

        auto pre = HD;
        while (nil) {
        	nil = nil->next;
        	pre = pre->next;
        }

        auto ndl = pre->next;
        pre->next = ndl->next;
        delete ndl;

        return HD->next;
    }
};