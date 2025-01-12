class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
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
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
        {
            return ret[right];
        }
        return ret[right] - ret[left - 1];
    }
    vector<int> ret;
};