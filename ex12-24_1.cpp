class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> st1(numRows, vector<int>());
        for (int i = 0; i < numRows; i++)
        {
            st1[i].resize(i + 1, 1);
        }
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 1; j < st1[i].size() - 1; ++j)
            {
                st1[i][j] = st1[i - 1][j - 1] + st1[i - 1][j];
            }
        }
        return st1;
    }
};