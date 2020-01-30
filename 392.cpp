class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.size() == 0)
            return true;
        int s_ind = 0;
        for (int tt : t)
        {
            if (tt == s[s_ind])
            {
                s_ind++;
                if (s_ind >= s.size())
                    return true;
            }
        }
        return false;
    }
};