/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        // positive
        if (num == 1) return true;

        int i = 2;
        while (i <= num / i) {
            int tmpFactor = i*i;
            if (num % tmpFactor == 0) return isPerfectSquare(num / tmpFactor);
            i++;
        }
        return false;
    }
};
// @lc code=end

