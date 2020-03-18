/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string res;
        while (num && res.size() < 8) {
            int digit = num & 15;
            char digitChar;
            if (digit > 9) digitChar = 'a' + digit - 10;
            else digitChar = '0' + digit;
            res = digitChar + res;
            num >>= 4;
        }
        return res;
    }
};
// @lc code=end

