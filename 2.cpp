/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode *res = NULL, *former = NULL;
        int digit = 0, adder = 0, tmpSum;
        while (l1 && l2)
        {
            tmpSum = l1->val + l2->val + adder;
            adder = tmpSum / 10;
            digit = tmpSum % 10;
            ListNode *cur = new ListNode(digit);
            if (!res)
                res = cur;
            else
                former->next = cur;
            former = cur;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            tmpSum = l1->val + adder;
            adder = tmpSum / 10;
            digit = tmpSum % 10;
            ListNode *cur = new ListNode(digit);
            if (!res)
                res = cur;
            else
                former->next = cur;
            former = cur;
            l1 = l1->next;
        }
        while (l2)
        {
            tmpSum = l2->val + adder;
            adder = tmpSum / 10;
            digit = tmpSum % 10;
            ListNode *cur = new ListNode(digit);
            if (!res)
                res = cur;
            else
                former->next = cur;
            former = cur;
            l2 = l2->next;
        }
        if (adder)
        {
            ListNode *cur = new ListNode(adder);
            former->next = cur;
        }
        return res;
    }
};