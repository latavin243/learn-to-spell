/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        return comb(n, k, 1);
    }

private:
    vector<vector<int>> comb(int n, int k, int start) {
        vector<vector<int>> res;
        if (k == 0) return res;
        if (k > n-start+1) return res;
        if (k == 1) {
            for (int i = start; i <= n; i++) {
                res.push_back(vector<int>{i});
            }
            return res;
        }

        res = comb(n, k, start+1);
        vector<vector<int>> tmp = comb(n, k-1, start+1);
        for (auto v:tmp) {
            // v.push_front(start);
            v.insert(v.begin(), start);
            res.push_back(v);
        }
        return res;
    }
};
// @lc code=end

