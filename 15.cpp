class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;

        // sort and find
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = nums.size()-1;
            while (left < right) {
                int tmpSum = nums[i] + nums[left] + nums[right];
                if (tmpSum == 0) {
                    vector<int> cur{nums[i], nums[left], nums[right]};
                    res.push_back(cur);
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if (tmpSum < 0) left++;
                else right--;
            }
        }
        return res;
    }
};