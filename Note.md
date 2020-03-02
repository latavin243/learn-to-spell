## 一些通用的c++用法整理

vector
```c++
vector<int> cur{1, 2, 3};

// 排序
sort(v.begin(), v.end());

// 头部插入元素
v.insert(v.begin(), 1);
```

set
```c++
unordered_set<int> s;

// 判断不包含某个元素
if(s.find(element) == s.end())
    ...

// 去掉某元素
s.erase(s.find(element));
```

map
```c++
unordered_map<string, string> m = {
    {"RED","#FF0000"},
    {"GREEN","#00FF00"},
    {"BLUE","#0000FF"}
};
```

## 和最快解法算法一致

66, 15, 110

## 有待改进

16

## 其他笔记

58: 最快解法样例很精炼
```c++
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
```c++
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

136: 一堆数中只有一个出现次数为奇数, 有一个很巧妙的解法
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(auto temp : nums){
            result^=temp;
        }
        return result;
    }
};
```

169: 找众数, 较优解法
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        for (int num : nums) {
            if (count == 0) candidate = num;
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
```