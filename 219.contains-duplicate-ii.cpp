/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // window method
        int length = nums.size();
        if (length <= 1 || k <= 0) return false;
        k = min(k, length-1);
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) s.erase(nums[i-k-1]);
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end

