/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        if (s.size() == 0) return s;
        unordered_set<char> vowels = {
            'a', 'e', 'i', 'o', 'u',
            'A', 'E', 'I', 'O', 'U',
        };
        int left = 0, right = s.size()-1;
        while (left < right) {
            while (left < right && vowels.find(s[left]) == vowels.end()) left++;
            while (left < right && vowels.find(s[right]) == vowels.end()) right--;
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};
// @lc code=end

