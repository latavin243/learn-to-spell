## 一些通用的c++用法整理

vector
```c++
vector<int> cur{1, 2, 3};

// 排序
sort(v.begin(), v.end());

// 头部插入元素
v.insert(v.begin(), 1);
```

2D vector
```c++
vector<vector<int>> matrix(m, vector<int>(n, 0));
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

// 遍历
for (auto &it : m) {
    cout << it.first << endl; // key
    cout << it.second << endl; // value
}
```

priority queue
```c++
// 最小堆
priority_queue<int> q;

// 最大堆
priority_queue<int, vector<int>, greater<int>> q;

// 自定义
auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
priority_queue<int, vector<int>, decltype(cmp)> q3(cmp);
```

other
```c++
// 需要返回多个值, 使用引用传参
bool getHeightAndIsBalanced(TreeNode* t, int& height)
```

## 和最快解法算法一致

66, 15, 110, 412, 111, 169, 152, 189, 217, 175

## 有待改进

16, 887, 202(可用快慢指针思路), 447

## 未通过

289

## 需要多看discussion

148

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

152: 最大乘积子序列, 可以用动规思路, 注意有±两维, 但是实际写法可以只用两个变量记录, 不需要数组记录结果

189: 旋转列表, 使用三次反转 (reverse)
```c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+(k%nums.size()));
        reverse(nums.begin()+(k%nums.size()), nums.end());
    }
};
```

160: 找到两个链表相交的节点, 先获取两个链表长度, 计算插值Δ, 然后较短的一个先往前走差值Δ, 然后两个链表同时向前遍历, 比较是否为同一节点

168: 一行
```c++
return n == 0 ? "" : convertToTitle(n / 26) + (char) (--n % 26 + 'A');
```

383: 注意`map<T, int>`的判断条件 `if (!m.count(ch) || !m[ch])`

401: 神奇的数二进制1的数量的方法
```c++
if (bitset<10>(h << 6 | m).count() == num) ...
```