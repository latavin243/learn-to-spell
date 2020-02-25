class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        bool positive = true, isNumber = false;

        for (char ch : str) {
            if (ch == ' ') {
                if (isNumber) return res;
                continue;
            }
            else if (ch == '-') {
                if (isNumber) return res;
                isNumber = true;
                positive = false;

            }
            else if (ch == '+') {
                if (isNumber) return res;
                isNumber = true;
                positive = true;
            }
            else if (ch >= '0' && ch <= '9') {
                if (!isNumber) isNumber = true;
                int digit = ch-'0';
                if (positive) {
                    if (res > INT_MAX / 10 || res * 10 > INT_MAX - digit) return INT_MAX;
                    res = res * 10 + digit;
                } else {
                    if (res < INT_MIN / 10 || res * 10 < INT_MIN + digit)
                        return INT_MIN;
                    res = res * 10 - digit;
                }
            }
            else {
                if (isNumber) return res;
                else return 0;
            }
        }
        return res;
    }
};

