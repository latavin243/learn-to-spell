class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int tmp;
                if (word1[i - 1] == word2[j - 1])
                    tmp = dp[i - 1][j - 1];
                else
                    tmp = dp[i - 1][j - 1] + 1;
                tmp = min(tmp, dp[i][j - 1] + 1);
                tmp = min(tmp, dp[i - 1][j] + 1);
                dp[i][j] = tmp;
            }
        }
        return dp[m][n];
    }
};