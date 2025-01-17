class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int sum = 0, ret = 0;
        for (const auto &e : nums)
        {
            sum += e;
            if (hash.count((sum % k + k) % k))
            {
                ret += hash[(sum % k + k) % k];
            }
            hash[(sum % k + k) % k]++;
        }
        return ret;
    }
};