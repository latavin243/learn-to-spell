66: 和最快解法算法一致, 有vector头部插入元素的方法`v.insert(v.begin(), 1);`

58: 最快解法样例很精炼
```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0,r=s.size()-1;
        for(;r>=0;r--){
            if(s[r]!=' ') break;
        }
        for(;r>=0;r--){
            if(s[r]==' ') break;
            else ans++;
        }
        return ans;
    }
};
```

21: 新的链表生成的时候可以先创建一个辅助的首节点dummy, 最后return dummy->next, 另外不需要生成新的节点, 直接借用原链表l1和l2的节点指针即可
```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(INT_MIN);
        ListNode *cur = &dummy;

        while(l1 && l2)
        {
            if(l1->val <= l2->val) cur->next = l1, l1 = l1->next;
            else cur->next = l2, l2 = l2->next;
            cur = cur->next;
        }
        cur->next = l1?l1:l2;
        return dummy.next;
    }
};
```

15: 创建一个新vector `vector<int> cur{nums[i], nums[left], nums[right]};`, 算法逻辑和最优情况一致

16: 有待提高