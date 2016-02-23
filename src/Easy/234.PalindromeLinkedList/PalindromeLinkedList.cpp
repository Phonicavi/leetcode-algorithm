#include <iostream>
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL||head->next == NULL) return true;

        ListNode *slowPointer, *fastPointer;
        slowPointer = fastPointer = head;

        while (fastPointer&&fastPointer->next) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }
        if (fastPointer) {
            slowPointer->next = reverseList(slowPointer->next);
            slowPointer = slowPointer->next;
        } else {
            slowPointer = reverseList(slowPointer);
        }

        while (slowPointer) {
            if (head->val != slowPointer->val) return false;
            head = head->next;
            slowPointer = slowPointer->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL||head->next == NULL) return head;
        auto rem = head->next;
        auto ans = reverseList(rem);
        rem->next = head;
        head->next = NULL;
        return ans;
    }

    bool isPalindrome2(ListNode* head) {
        if (head == NULL||head->next == NULL) return true;
        
        ListNode *cur = new ListNode(head->val), *ori = cur;
        ListNode *tmp = head;
        while (tmp->next) {
            cur->next = new ListNode((tmp->next)->val);
            cur = cur->next;
            tmp = tmp->next;
        }

        auto anti = reverseList(ori);
        while (head && anti) {
            if (head->val != anti->val) return false;
            head = head->next;
            anti = anti->next;
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    ListNode head = ListNode(1);
    ListNode tail = ListNode(2);
    head.next = &tail;

    Solution a = Solution();
    cout<<a.isPalindrome(&head)<<endl;

    return 0;
}