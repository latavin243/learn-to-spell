// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         // non-empty, must exist, more than n/2 times
//         unordered_map<int, int> m;
//         for (int n : nums) {
//             m[n]++;
//             if (m[n] > nums.size() / 2) return n;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // non-empty, must exist, more than n/2 times
        int curNum = 0, count = 0;
        for (int n : nums) {
            if (count == 0) {
                curNum = n;
                count = 1;
                continue;
            }

            if (n == curNum) count++;
            else count--;

        }
        return curNum;
    }
};