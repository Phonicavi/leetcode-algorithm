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
    ListNode* swapPairs(ListNode* head) {
        if (!head||!(head->next)) return head;
        auto pre = head, cur = head->next, ppre = head;
        auto ans = cur;
        ppre = NULL;

        while (pre&&cur) {
            // std::cout<<pre->val<<std::endl<<cur->val<<std::endl;
        	auto nxt = cur->next;
        	if (ppre) ppre->next = cur;
    		pre->next = nxt;
    		cur->next = pre;
    		ppre = pre;
    		if (!nxt||!(nxt->next)) break;
    		pre = nxt, cur = nxt->next;
        }
        return ans;
    }
};