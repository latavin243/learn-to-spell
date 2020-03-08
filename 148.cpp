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
    ListNode* sortList(ListNode* head) {
        // bubble sort
        if (!head || !head->next) return head;

        while (true) {
            ListNode *cur = head;
            bool isChanged = false;
            while (cur->next) {
                if (cur->val > cur->next->val) {
                    int tmp = cur->val;
                    cur->val = cur->next->val;
                    cur->next->val = tmp;
                    isChanged = true;
                }
                cur = cur->next;
            }
            if (!isChanged) return head;
        }
    }
};