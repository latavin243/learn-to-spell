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