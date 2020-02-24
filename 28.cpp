class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.size() == 0 && needle.size() == 0)
            return 0;
        if (haystack.size() < needle.size())
            return -1;

        for (int i = 0; i <= haystack.size() - needle.size(); i++)
        {
            bool contains = true;
            for (int j = 0; j < needle.size(); j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    contains = false;
                    break;
                }
            }
            if (contains)
                return i;
        }
        return -1;
    }
};