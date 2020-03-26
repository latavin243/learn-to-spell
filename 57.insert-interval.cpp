/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // intervals: sorted, non-overlapping
        vector<vector<int>> res;
        if (intervals.empty()) {
            res.push_back(newInterval);
            return res;
        }

        // skip former non-overlapping intervals
        int i = 0;
        while (i < intervals.size() && newInterval[0] > intervals[i][1]) {
            res.push_back(intervals[i]);
            i++;
        }
        res.push_back(newInterval);

        // merge
        for (; i < intervals.size(); i++) {
            if (intervals[i][0] > newInterval[1]) break;
            else {
                res.back()[0] = min(res.back()[0], min(newInterval[0], intervals[i][0]));
                res.back()[1] = max(res.back()[1], max(newInterval[1], intervals[i][1]));
            }
        }

        // skip latter non-overlapping intervals
        while (i < intervals.size()) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
// @lc code=end

