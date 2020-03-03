class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N+1, vector<int> (K+1, 0));
        // m: times of drop, k: egg number, dp[m][k]: floors can reach
        int m = 0;
        while(dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; k++)
                dp[m][k] = dp[m-1][k] + dp[m-1][k-1] + 1;
        }
        return m;
    }
};