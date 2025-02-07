class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ret;
        for (int i = 0; i < n;)
        {
            int a = nums[i];
            for (int j = i + 1; j < n;)
            {
                int b = nums[j];
                int left = j + 1;
                int right = n - 1;
                while (left < right)
                {
                    int sum = nums[left] + nums[right];
                    long long aim = (long long)target - a - b;
                    if (sum < aim)
                    {
                        left++;
                    }
                    else if (sum > aim)
                    {
                        right--;
                    }
                    else
                    {
                        ret.push_back({a, b, nums[left], nums[right]});
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
                j++;
                while (j < n && nums[j] == nums[j - 1])
                {
                    j++;
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