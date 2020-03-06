class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, count = 0;
        for (int n : nums) {
            if (n == 0) count++;
            else nums[i++] = n;
        }
        while (count > 0) {
            nums[i++] = 0;
            count--;
        }
    }
};