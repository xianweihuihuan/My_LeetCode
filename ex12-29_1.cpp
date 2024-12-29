class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_map<string, int> hash1;
        for (auto e : words)
        {
            hash1[e]++;
        }
        int len = words[0].size(), m = words.size();
        vector<int> ret;
        for (int i = 0; i < len; i++)
        {
            unordered_map<string, int> hash2;
            for (int left = i, right = i, count = 0; right + len <= s.size();
                 right += len)
            {
                string in = s.substr(right, len);
                hash2[in]++;
                if (hash2[in] <= hash1[in])
                {
                    count++;
                }
                if (right - left + 1 > len * m)
                {
                    string out = s.substr(left, len);
                    if (hash2[out] <= hash1[out])
                    {
                        count--;
                    }
                    hash2[out]--;
                    left += len;
                }
                if (count == m)
                {
                    ret.push_back(left);
                }
            }
        }
        return ret;
    }
};