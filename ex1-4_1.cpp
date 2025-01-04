class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        if (nums.size() == 0 || nums.size() == 1)
        {
            return false;
        }
        map<int, int> s1;
        int left = 0, right = 0;
        int ret = INT_MAX;
        for (; right < nums.size(); ++right)
        {
            s1[nums[right]]++;
            while (s1[nums[right]] == 2)
            {
                s1[nums[left]]--;
                left++;
                if (s1[nums[right]] == 1)
                {
                    ret = min(ret, right - left + 1);
                }
            }
        }
        if (ret <= k)
        {
            return true;
        }
        return false;
    }
};