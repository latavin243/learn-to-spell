class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0)
            return 0;
        if (x == INT_MIN)
            return 0;
        if (x < 0)
            return -reverse(-x);

        vector<int> digits;
        while (x % 10 == 0)
            x /= 10;
        while (x)
        {
            digits.push_back(x % 10);
            x /= 10;
        }
        int res = 0;
        for (auto i : digits)
        {
            if (res > INT_MAX / 10)
                return 0;
            if (res * 10 > INT_MAX - i)
                return 0;
            res = res * 10 + i;
        }
        return res;
    }
};