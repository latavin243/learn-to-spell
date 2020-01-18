class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
        {
            return 1;
        }
        vector<int> m = {1, 1};
        int i = 2;
        while (i <= n)
        {
            int tmp = m[i - 1] + m[i - 2];
            m.push_back(tmp);
            i++;
        }
        return m[n];
    }
};