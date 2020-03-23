/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        // n > 0
        // find i(i+1)/2 < n < (i+1)(i+2)/2
        long i = 1;
        while (n >= i*(i+1)/2) i++;
        return i-1;
    }
};
// @lc code=end

