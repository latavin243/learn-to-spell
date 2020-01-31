class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";

        string cur_prefix = strs[0];
        for (int i = 0; i < strs.size(); i++)
        {
            cur_prefix = commonPrefix(cur_prefix, strs[i]);
        }
        return cur_prefix;
    }

    string commonPrefix(string s1, string s2)
    {
        string common_prefix = "";
        int max_len = min(s1.size(), s2.size());
        for (int i = 0; i < max_len; i++)
        {
            if (s1[i] == s2[i])
                common_prefix += s1[i];
            else
                break;
        }
        return common_prefix;
    }
};

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if(strs.size()==0){
//             return "";
//         }
//         string prefix = strs[0];
//         for(int i=1;i<strs.size();i++){
//             while(strs[i].find(prefix) != 0){
//                 prefix = prefix.substr(0,prefix.length()-1);
//             }
//         }
//         return prefix;
//     }
// };