class Solution
{
public:
    struct Compare
    {
        bool operator()(const pair<int, int> &kv1, const pair<int, int> &kv2)
        {
            return kv1.second > kv2.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> hash;
        for (const auto &e : nums)
        {
            hash[e]++;
        }
        vector<pair<int, int>> ks(hash.begin(), hash.end());
        sort(ks.begin(), ks.end(), Compare());
        vector<int> ret;
        for (int i = 0; i < k; i++)
        {
            ret.push_back(ks[i].first);
        }
        return ret;
    }
};