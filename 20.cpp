class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> tmp;
        for (char ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
                tmp.push(ch);
            else
            {
                if (tmp.empty())
                    return false;
                if (ch == ')')
                {
                    if (tmp.top() != '(')
                        return false;
                }
                else if (ch == ']')
                {
                    if (tmp.top() != '[')
                        return false;
                }
                else if (ch == '}')
                {
                    if (tmp.top() != '{')
                        return false;
                }
                tmp.pop();
            }
        }
        if (!tmp.empty())
            return false;
        return true;
    }
};