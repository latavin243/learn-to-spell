class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        vector<int> digit_list;
        while (x)
        {
            digit_list.push_back(x % 10);
            x /= 10;
        }
        int left = 0, right = digit_list.size() - 1;
        while (left <= right)
        {
            if (digit_list[left] != digit_list[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};