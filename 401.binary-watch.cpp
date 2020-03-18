/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        // hours (0-11), minutes (0-59)
        vector<string> res;
        for (int hour = 0; hour <= 11; hour++) {
            for (int minute = 0; minute <= 59; minute++) {
                if (bitCount(hour) + bitCount(minute) == num)
                    res.push_back(constructTimeString(hour, minute));
            }
        }
        return res;
    }

private:
    string constructTimeString(int hour, int minute) {
        return to_string(hour) + (minute < 10 ? ":0" : ":") + to_string(minute);
    }

    int bitCount(int n) {
        int res = 0;
        while (n) {
            if (n&1) res++;
            n >>= 1;
        }
        return res;
    }
};
// @lc code=end

