class Solution
{
public:
    string convert(string s, int numRows)
    {
        /*
        m = 2 * n - 2
        i%m

        0
        1, m-1
        2, m-2
        ...
        n-2, n
        n-1
        */
        if (numRows <= 1 || s.size() <= numRows)
            return s;

        string res = "";
        int m = 2 * numRows - 2; // mod

        for (int i = 0; i <= numRows - 1; i++) // row
        {
            for (int j = 0; j < s.size(); j += m) // period beginning num
            {
                if (i == 0 || i == numRows - 1)
                {
                    if (i + j < s.size())
                        res += s[i + j];
                }
                else
                {
                    if (j + i < s.size())
                        res += s[j + i];
                    if (j + m - i < s.size())
                        res += s[j + m - i];
                }
            }
        }
        return res;
    }
};