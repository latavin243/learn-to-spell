class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        int len = nums.size();
        if (len <= 1) {
            return res;
        }

        // reverse index
        for (int i = 0; i < len; i++) {
            m[nums[i]] = i;
        }

        for (int i = 0; i < len; i++) {
            int t = target - nums[i];
            if (m.find(t) != m.end() && m[t] != i) {
                res.push_back(i);
                res.push_back(m[t]);
                return res;
            }
        }
        return res;
    }
};
