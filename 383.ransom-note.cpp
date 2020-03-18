/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (char ch : magazine) m[ch]++;
        for (char ch : ransomNote) {
            if (!m.count(ch) || !m[ch]) return false;
            else m[ch]--;
        }
        return true;
    }
};
// @lc code=end
