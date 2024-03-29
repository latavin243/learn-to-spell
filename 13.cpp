// 区分加减, 如果是最后一位或者前一位大于后一位则加, 否则减
class Solution
{
public:
    int romanToInt(string s)
    {
        int res = 0;
        unordered_map<char, int> m{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        for (int i = 0; i < s.size(); i++)
        {
            if (i == s.size() - 1 || m[s[i]] >= m[s[i + 1]])
                res += m[s[i]];
            else
                res -= m[s[i]];
        }
        return res;
    }
};