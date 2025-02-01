class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        int x = mat.size();
        int y = mat[0].size();
        vector<vector<int>> dp(x + 1, vector<int>(y + 1));
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        vector<vector<int>> ret(x, vector<int>(y));
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                int x1 = max(0, i - k) + 1;
                int y1 = max(0, j - k) + 1;
                int x2 = min(x - 1, i + k) + 1;
                int y2 = min(y - 1, j + k) + 1;
                ret[i][j] = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
            }
        }
        return ret;
    }
};