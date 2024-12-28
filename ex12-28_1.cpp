class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int hash1[1000] = {0}; // 统计string p 中每个字符的个数
        int hash2[1000] = {0};
        vector<int> ret;
        int count = 0;
        int m = p.size();
        for (auto e : p)
        {
            hash1[e]++;
        }
        for (int left = 0, right = 0; right < s.size(); right++)
        {
            char in = s[right];
            if (++hash2[in] <= hash1[in])
            {
                count++;
            }
            if (right - left + 1 > m)
            {
                char out = s[left++];
                if (hash2[out]-- <= hash1[out])
                {
                    count--;
                }
            }
            if (count == m)
            {
                ret.push_back(left);
            }
        }
        return ret;
    }
};