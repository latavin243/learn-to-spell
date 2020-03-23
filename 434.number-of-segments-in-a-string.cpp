/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        bool isRecording = false;
        int res = 0;
        for (char ch : s) {
            if (!isRecording) {
                if (ch == ' ') continue;
                else {
                    isRecording = true;
                    res++;
                }
            } else {
                if (ch != ' ') continue;
                else isRecording = false;
            }
        }
        return res;
    }
};
// @lc code=end

