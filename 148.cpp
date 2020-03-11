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
        // merge sort
        // https://leetcode.com/problems/sort-list/discuss/46712/Bottom-to-up(not-recurring)-with-o(1)-space-complextity-and-o(nlgn)-time-complextity
        if (!head || !head->next) return head;

        int length = getLength(head);
        ListNode dummy(0); // instance access using dot(.)
        dummy.next = head;
        ListNode *cur, *left, *right, *tail;
        for (int step = 1; step < length; step <<= 1) {
            cur = dummy.next;
            tail = &dummy;
            while (cur) {
                left = cur;
                right = split(left, step);
                cur = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        return dummy.next;
    }

private:
    int getLength(ListNode* head) {
        ListNode *cur = head;
        int length = 0;
        while(cur) {
            length++;
            cur = cur->next;
        }
        return length;
    }

    ListNode* split(ListNode* cur, int step) {
        for (int i = 0; cur && i < step; i++) cur = cur->next;
        if (!cur) return NULL;
        ListNode *second = cur->next;
        cur->next = NULL;
        return second;
    }

    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head) {
        ListNode *cur = head;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            } else {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
        }
        cur->next = (l1 ? l1 : l2);
        while (cur->next) cur = cur->next;
        return cur;
    }
};