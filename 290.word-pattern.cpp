/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = getWordSplit(str);
        if (words.size() != pattern.size()) return false;

        unordered_map<char, string> m;
        unordered_set<string> s;
        for (int i = 0; i < pattern.size(); i++) {
            string word = words[i];
            char sign = pattern[i];
            if (m.find(sign) == m.end()) {
                if (s.find(word) == s.end()) {
                    m[sign] = word;
                    s.insert(word);
                }
                else return false;
            }
            else if (m[sign] != word) return false;
        }
        return true;
    }

private:
    vector<string> getWordSplit(string str) {
        vector<string> res;
        string tmpWord = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                if (tmpWord.empty()) continue;
                else {
                    res.push_back(tmpWord);
                    tmpWord = "";
                }
            }
            else tmpWord += str[i];
        }
        res.push_back(tmpWord);
        return res;
    }
};
// @lc code=end

