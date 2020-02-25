class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        // non-empty
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] == 9)
                digits[i] = 0;
            else
            {
                digits[i] = digits[i] + 1;
                return digits;
            }
        }
        digits.insert(digits.begin(), 1); // add element to the beginning of vector
        return digits;
    }
};