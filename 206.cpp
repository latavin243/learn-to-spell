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
        if (!head) return head;

        ListNode *pre = head, *cur = head->next;
        head->next = NULL;
        while (cur) {
            ListNode *tmp = cur;
            cur = cur->next;
            tmp->next = pre;
            pre = tmp;
        }
        return pre;
    }
};