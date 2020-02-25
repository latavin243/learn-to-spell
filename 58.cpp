class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.size() == 0)
            return 0;

        int res = 0, count = 0;
        bool recording = false;
        for (char ch : s)
        {
            if (ch == ' ')
            {
                if (recording)
                {
                    res = count;
                    count = 0;
                    recording = false;
                }
            }
            else
            {
                count++;
                if (!recording)
                    recording = true;
            }
        }
        if (count > 0)
            res = count;
        return res;
    }
};