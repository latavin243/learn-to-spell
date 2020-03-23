/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() <= 1) return chars.size();
        int i = 0, j = 1, cur = 0;
        while (i < chars.size()) {
            bool isRepeat = false;
            while (j < chars.size() && chars[j] == chars[i]) {
                isRepeat = true;
                j++;
            }
            chars[cur++] = chars[i];
            if (isRepeat) {
                // may be more than 1 digit
                for (char ch : to_string(j-i)) chars[cur++] = ch;
            }
            i = j;
            j++;
        }
        return cur;
    }
};
// @lc code=end

