class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {

        vector<int> hs(nums.size() + 1);
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                nums[i] = -1;
            }
        }
        unordered_map<int, int> hash;
        hash[0] = -1;
        int sum = 0;
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (hash.count(sum))
            {
                ret = max(ret, i - hash[sum]);
            }
            else
            {
                hash[sum] = i;
            }
        }
        return ret;
    }
};