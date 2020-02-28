class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // condition: one solution
        int res = nums[0] + nums[1] + nums[2], numsLen = nums.size();
        for(int i = 0; i < numsLen; i++) {
            for (int j = i+1; j < numsLen; j++) {
                for(int k = j+1; k < numsLen; k++) {
                    int curSum = nums[i] + nums[j] + nums[k];
                    if(abs(curSum - target) < abs(res - target)) res = curSum;
                }
            }
        }
        return res;
    }
};