class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int hash1[200] = {0};
        int hash2[200] = {0};
        int sz = 0;
        int count = 0;
        for (const auto &e : s1)
        {
            hash1[e]++;
            if (hash1[e] == 1)
            {
                sz++;
            }
        }
        int n = s1.size();
        int left = 0;
        int right = 0;
        for (; right < s2.size(); right++)
        {
            char out = s2[right];
            hash2[out]++;
            if (hash2[out] == hash1[out])
            {
                count++;
            }
            while (right - left + 1 > n)
            {
                char in = s2[left];
                if (hash2[in] == hash1[in])
                {
                    count--;
                }
                hash2[in]--;
                left++;
            }
            if (count == sz)
            {
                return true;
            }
        }
        return false;
    }
};