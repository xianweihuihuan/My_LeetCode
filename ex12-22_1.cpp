class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int tmp = 0;
        for (auto tmo : nums)
        {
            tmp ^= tmo;
        }
        return tmp;
    }
};