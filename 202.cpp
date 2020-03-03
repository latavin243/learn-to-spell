class Solution {
public:
    bool isHappy(int n) {
        if (n == 0) return false;

        unordered_set<int> s;
        while (n != 1) {
            if (s.find(n) != s.end()) return false;
            s.insert(n);
            n = squareSum(n);
        }
        return true;
    }

    int squareSum(int n) {
        int res = 0;
        while (n) {
            int digit = n%10;
            res += digit * digit;
            n /= 10;
        }
        return res;
    }
};