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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *fast = head->next->next, *slow = head->next;
        while (fast) {
            if (fast == slow) return true;
            if (!fast->next || !fast->next->next) return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};