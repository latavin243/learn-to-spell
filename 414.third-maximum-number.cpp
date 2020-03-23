/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // third distinct max number
        // if not exist return max
        priority_queue<int, vector<int>, greater<int>> q;
        unordered_set<int> s;
        for (int n : nums) {
            if (q.size() < 3 && s.find(n) == s.end()) {
                s.insert(n);
                q.push(n);
            } else if (n > q.top() && s.find(n) == s.end()) {
                s.erase(s.find(q.top()));
                q.pop();
                s.insert(n);
                q.push(n);
            }
        }
        if (q.size() < 3) {
            while (q.size() > 1) q.pop();
        }
        return q.top();
    }
};
// @lc code=end

