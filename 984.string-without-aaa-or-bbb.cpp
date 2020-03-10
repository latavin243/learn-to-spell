/*
 * @lc app=leetcode id=984 lang=cpp
 *
 * [984] String Without AAA or BBB
 */

// @lc code=start
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string res, c1 = "a", c2 = "b";
        if (A < B) {
            swap(c1, c2);
            swap(A, B);
        }

        while (A > B && B > 0) {
            res += c1 + c1 + c2;
            A -= 2;
            B--;
        }

        if (B == 0) {
            switch (A)
            { // A = 0, 1 or 2
                case 1:
                    res += c1;
                    break;
                case 2:
                    res += c1 + c1;
                    break;
            }
            return res;
        }

        // A == B > 0
        while (A) {
            res += c1 + c2;
            A--;
        }
        return res;
    }
};
// @lc code=end

