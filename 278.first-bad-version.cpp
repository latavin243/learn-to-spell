/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right-left) / 2;
            if (!isBadVersion(mid) && isBadVersion(mid+1)) return mid+1;
            if (isBadVersion(mid)) right = mid;
            else left = mid;
        }
        return left;
    }
};
// @lc code=end

