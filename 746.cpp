class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp;
        for (int i = 0; i <= n; i++)
        {
            if (i <= 1)
            {
                dp.push_back(0);
                continue;
            }
            dp.push_back(min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]));
        }
        return dp[n];
    }
};