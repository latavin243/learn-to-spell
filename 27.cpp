class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int removed = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                removed++;
                continue;
            }
            else
            {
                nums[i - removed] = nums[i];
            }
        }
        return nums.size() - removed;
    }
};