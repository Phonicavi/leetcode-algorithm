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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		auto *p1 = headA, *p2 = headB;
        if (!p1||!p2) return NULL;

        while (p1 != p2) {
        	p1 = p1->next;
        	p2 = p2->next;
        	if (p1 == p2) return p1;
        	if (p1 == NULL) p1 = headB; // p2
        	if (p2 == NULL) p2 = headA; // p1
        }
        return p1;
	}

    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        auto *p1 = headA, *p2 = headB;
        if (!p1||!p2) return NULL;
        int lengthA = 0, lengthB = 0;

        while (p1) {
        	p1 = p1->next;
        	++lengthA;
        }
        while (p2) {
        	p2 = p2->next;
        	++lengthB;
        }
        int diff = abs(lengthA - lengthB);

        p1 = headA;
        p2 = headB;
        if (lengthA > lengthB) {
			for (int i=0; i<diff; ++i) p1 = p1->next;
        } else {
			for (int i=0; i<diff; ++i) p2 = p2->next;
        }

    	while (p1 != p2) {
    		p1 = p1->next;
    		p2 = p2->next;
    	}

    	return p1;
    }
};