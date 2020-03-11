/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        int cur, pre;
        for (int i = 0; i <= rowIndex; i++) {
            if (i == 0) cur = 1;
            else if (i > rowIndex - i) cur = res[rowIndex - i];
            else {
                long tmp = pre;
                tmp = tmp * (rowIndex - i + 1) / i;
                cur = int(tmp);
            }
            res.push_back(cur);
            pre = cur;
        }
        return res;
    }
};
// @lc code=end

