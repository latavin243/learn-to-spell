/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray {
private:
vector<long> sumArray;

public:
    NumArray(vector<int>& nums) {
        long sum = 0;
        sumArray.push_back(sum);
        for (int n : nums) {
            sum += n;
            sumArray.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return int(sumArray[j+1] - sumArray[i]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

