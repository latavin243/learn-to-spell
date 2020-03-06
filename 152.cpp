class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // choose i, then the max/min dubarray product is dp[i]
        // dp[i, 0] max (+), dp[i, 1] min (-)
        // return max(dp[n,0], dp[n-1,0], ... dp[0,0])
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        int res = nums[0], preMax = 1, preMin = 1, curMax = 0, curMin = 0;
        for (int n : nums) {
            if (n > 0) {
                curMax = preMax * n;
                curMin = preMin * n;
            } else {
                curMin = preMax * n;
                curMax = preMin * n;
            }
            curMax = max(curMax, n);
            curMin = min(curMin, n);

            res = max(res, curMax);
            preMax = curMax;
            preMin = curMin;
        }
        return res;
    }
};