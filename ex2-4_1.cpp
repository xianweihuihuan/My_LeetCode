class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ret;
        map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.count(nums[i]))
            {
                if (2 * nums[i] == target)
                {
                    ret.push_back(hash[nums[i]]);
                    ret.push_back(i);
                    return ret;
                }
            }
            else
            {
                hash[nums[i]] = i;
            }
        }
        vector<pair<int, int>> tmp;
        for (auto e : hash)
        {
            tmp.push_back(e);
        }
        int left = 0;
        int right = tmp.size() - 1;
        while (left < right)
        {
            int sum = tmp[left].first + tmp[right].first;
            if (sum < target)
            {
                left++;
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                ret.push_back(tmp[left].second);
                ret.push_back(tmp[right].second);
                return ret;
            }
        }
        return ret;
    }
};