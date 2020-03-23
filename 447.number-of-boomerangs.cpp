/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 */

// @lc code=start
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        // n <= 500, x, y in [-10000, 10000]
        int count = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> m;
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                m[dx*dx+dy*dy]++;
            }
            for (auto &it : m) count += it.second * (it.second - 1);
        }
        return count;
    }
};
// @lc code=end

