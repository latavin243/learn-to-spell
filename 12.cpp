// 贪婪法, 尽可能减掉靠前的大数, 并拼凑最终罗马数字string
class Solution {
public:
    string intToRoman(int num) {
        vector<string> seg_str = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> seg_num = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string res = "";
        int i = 0;
        while (num > 0) {
            if (num < seg_num[i]) i++;
            else {
                num -= seg_num[i];
                res += seg_str[i];
            }
            if (num == 0) return res;
        }
        return res;
    }
};