class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // k >= 0
        if (nums.size() <= 1 || k == 0) return;

        int len = nums.size();
        k = k % len;
        reverse(nums, 0, len-k-1);
        reverse(nums, len-k, len-1);
        reverse(nums, 0, len-1);
    }

private:
    void reverse(vector<int>& nums, int left, int right) {
        while(left < right) swap(nums[left++], nums[right--]);
    }
};