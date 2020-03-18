/*
 * @lc app=leetcode id=1281 lang=cpp
 *
 * [1281] Subtract the Product and Sum of Digits of an Integer
 */

// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n) {
        // 1 <= n <= 10^5
        int prod = 1, sum = 0;
        while (n) {
            int digit = n % 10;
            prod *= digit;
            sum += digit;
            n /= 10;
        }
        return prod - sum;
    }
};
// @lc code=end

