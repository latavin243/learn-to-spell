class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> dp = {triangle[0]};
        for (int row = 1; row < triangle.size(); row++)
        {
            vector<int> dp_row;
            for (int col = 0; col < triangle[row].size(); col++)
            {
                int last_min;
                if (col == 0)
                    last_min = dp[row - 1][0];
                else if (col == triangle[row].size() - 1)
                    last_min = dp[row - 1][col - 1];
                else
                    last_min = min(dp[row - 1][col], dp[row - 1][col - 1]);
                dp_row.push_back(triangle[row][col] + last_min);
            }
            dp.push_back(dp_row);
        }

        int min_result = INT_MAX;
        vector<int> dp_last_row = dp[dp.size() - 1];
        for (int i = 0; i < dp_last_row.size(); i++)
            min_result = min(dp_last_row[i], min_result);
        return min_result;
    }
};