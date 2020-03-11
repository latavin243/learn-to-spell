/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        // n > 0
        string res;
        stack<char> s;
        while (n) {
            n--;
            char ch = 'A' + (n % 26);
            s.push(ch);
            n /= 26;
        }
        while (!s.empty()) {
            res += s.top();
            s.pop();
        }
        return res;
    }
};
// @lc code=end

