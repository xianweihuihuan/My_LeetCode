class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int d)
    {
        int ret = 0;
        for (int i = 1; i < timeSeries.size(); i++)
        {
            int tmp = timeSeries[i] - timeSeries[i - 1];
            if (tmp >= d)
            {
                ret += d;
            }
            else
            {
                ret += tmp;
            }
        }
        ret += d;
        return ret;
    }
};