class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return 0;
        if (nums[0] > target)
            return 0;

        int len = nums.size();
        if (nums[len - 1] < target)
            return len;

        int left = 0, right = len - 1;
        while (true)
        {
            int mid = (left + right) / 2;
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid])
            {
                if (target > nums[mid - 1])
                    return mid;
                right = mid - 1;
            }
            else
            {
                if (target < nums[mid + 1])
                    return mid + 1;
                left = mid + 1;
            }
        }
        return -1;
    }
};