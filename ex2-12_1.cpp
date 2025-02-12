class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int ret = 0;
        for (const auto e : nums)
        {
            ret ^= e;
        }
        for (int i = 1; i <= nums.size(); i++)
        {
            ret ^= i;
        }
        return ret;
    }
};