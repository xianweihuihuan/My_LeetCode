class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int n = nums.size();
        for (int i = 0; i < n;)
        {
            if (nums[i] > 0)
            {
                break;
            }
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum > 0 - nums[i])
                {
                    right--;
                }
                else if (sum < 0 - nums[i])
                {
                    left++;
                }
                else
                {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
            }
            i++;
            while (i < n && nums[i] == nums[i - 1])
            {
                i++;
            }
        }
        return ret;
    }
};