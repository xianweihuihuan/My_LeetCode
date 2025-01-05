class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        map<int, int, greater<int>> s1;
        int left = 0;
        int right = 0;
        vector<int> ret;
        for (; right < nums.size(); right++)
        {
            s1[nums[right]]++;
            while (right - left + 1 > k)
            {
                s1[nums[left]]--;
                if (s1[nums[left]] == 0)
                {
                    s1.erase(nums[left]);
                }
                left++;
            }
            if (right - left + 1 == k)
            {
                auto e = s1.begin();
                ret.push_back(e->first);
            }
        }
        return ret;
    }
};
