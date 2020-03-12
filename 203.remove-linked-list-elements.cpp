/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        ListNode dummy(0);
        ListNode *pre = &dummy, *cur = head;
        dummy.next = head;
        while (cur) {
            if (cur->val == val) pre->next = cur->next;
            else pre = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};
// @lc code=end

