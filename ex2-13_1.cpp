class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int tmp = 0;
        for (auto e : nums)
        {
            tmp ^= e;
        }
        vector<int> ret;
        int diff = 0;
        while (true)
        {
            if (((tmp >> diff) & 1) == 1)
            {
                break;
            }
            else
            {
                diff++;
            }
        }
        int a = 0, b = 0;
        for (auto x : nums)
        {
            if (((x >> diff) & 1) == 1)
            {
                a ^= x;
            }
            else
            {
                b ^= x;
            }
        }
        ret.push_back(a);
        ret.push_back(b);
        return ret;
    }
};