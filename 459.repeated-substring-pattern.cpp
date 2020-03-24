/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // length < 10000, lowercase
        string substring = "";
        for (int i = 0; i < s.size()/2; i++) {
            substring += s[i];
            int period = substring.size();
            if (s.size() % period != 0) continue;

            bool isRepeated = true;
            for (int j = period; j < s.size(); j++) {
                if (substring[j%period] != s[j]) {
                    isRepeated = false;
                    break;
                }
            }
            if (isRepeated) return true;
        }
        return false;
    }
};
// @lc code=end

