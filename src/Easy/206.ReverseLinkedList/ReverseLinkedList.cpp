#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL||head->next == NULL) return head;
        auto rem = head->next;
        auto ans = reverseList(rem);
        rem->next = head;
        head->next = NULL;
        return ans;
    }
    
    ListNode* reverseList2(ListNode* head) {
        if (head == NULL||head->next == NULL) return head;

        ListNode *curr, *tmp, *nxt;
        curr = head;
        tmp = head->next;
        head->next = NULL;
        while (tmp->next!=NULL) {
            nxt = tmp->next;

            tmp->next = curr;
            curr = tmp;
            tmp = nxt;
        }
        tmp->next = curr;
        return tmp;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}