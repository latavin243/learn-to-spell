/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // s & t have same length
        unordered_map<char, char> m;
        unordered_set<char> tSet;
        for (int i = 0; i < s.size(); i++) {
            char a = s[i], b = t[i];
            if (m.find(a) == m.end()) {
                if (tSet.find(b) != tSet.end()) return false;
                m[a] = b;
                tSet.insert(b);
            } else {
                if (m[a] != b) return false;
            }
        }
        return true;
    }
};
// @lc code=end

