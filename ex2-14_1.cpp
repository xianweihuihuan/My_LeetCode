class Solution
{
public:
    vector<int> missingTwo(vector<int> &nums)
    {
        int tmp = 0;
        for (auto x : nums)
        {
            tmp ^= x;
        }
        for (int i = 1; i <= nums.size() + 2; i++)
        {
            tmp ^= i;
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
        for (int i = 1; i <= nums.size() + 2; i++)
        {
            if (((i >> diff) & 1) == 1)
            {
                a ^= i;
            }
            else
            {
                b ^= i;
            }
        }
        ret.push_back(a);
        ret.push_back(b);
        return ret;
    }
};