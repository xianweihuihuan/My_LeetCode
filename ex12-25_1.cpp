class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> vv(rowIndex + 1, vector<int>());
        for (int i = 0; i < rowIndex + 1; i++)
        {
            vv[i].resize(i + 1, 1);
        }
        for (int i = 0; i < rowIndex + 1; i++)
        {
            for (int j = 1; j < vv[i].size() - 1; ++j)
            {
                vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
            }
        }
        return vv[rowIndex];
    }
};