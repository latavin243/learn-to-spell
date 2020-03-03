class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K+1, vector<int> (N+1, 0));

        // one egg, K=1
        for (int j = 1; j <= N; j++)
            dp[1][j] = j;

        for (int i = 2; i <= K; i++) {
            for (int j = 1; j <= N; j++) {
                int tmp = j;
                for (int k = 1; k < j; k++) {
                    int worse = max(dp[i-1][k-1], dp[i][j-k]) + 1;
                    tmp = min(worse, tmp);
                }
                dp[i][j] = tmp;
            }
        }
        return dp[K][N];
    }
};