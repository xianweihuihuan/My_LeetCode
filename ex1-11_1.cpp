class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                ret.push_back(nums[i]);
            }
            else
            {
                int tmp = nums[i] + ret[i - 1];
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};