class Solution
{
public:
    struct Compare
    {
        bool operator()(const pair<string, int> &kv1, const pair<string, int> kv2)
        {
            return kv1.second > kv2.second;
        }
    };
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> hash;
        for (const auto &e : words)
        {
            hash[e]++;
        }
        vector<pair<string, int>> tmp(hash.begin(), hash.end());
        stable_sort(tmp.begin(), tmp.end(), Compare());
        vector<string> ret;
        for (int i = 0; i < k; i++)
        {
            ret.push_back(tmp[i].first);
        }
        return ret;
    }
};