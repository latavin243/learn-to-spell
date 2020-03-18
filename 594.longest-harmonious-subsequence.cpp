/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
            if (m.count(n+1)) res = max(res, m[n] + m[n+1]); // must check n+1 in m
            if (m.count(n-1)) res = max(res, m[n] + m[n-1]);
        }
        return res;
    }
};
// @lc code=end

