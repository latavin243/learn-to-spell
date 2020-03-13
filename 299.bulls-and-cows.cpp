/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        // length always equal
        unordered_map<char, int> mSecret, mGuess;
        int countA = 0, countB = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (guess[i] == secret[i]) countA++;
            else {
                mGuess[guess[i]]++;
                mSecret[secret[i]]++;
            }
        }
        for (auto& pair : mSecret) {
            countB += min(pair.second, mGuess[pair.first]);
        }
        return to_string(countA) + "A" + to_string(countB) + "B";
    }
};
// @lc code=end

