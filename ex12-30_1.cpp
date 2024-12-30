class Solution
{
public:
    string minWindow(string s, string t)
    {
        int hash1[200] = {0};
        int m = 0;
        for (auto tmp : t)
        {
            if (hash1[tmp] == 0)
            {
                m++;
            }
            hash1[tmp]++;
        }
        int pos = -1;
        int len = INT_MAX;
        int hash2[200] = {0};
        int count = 0;
        for (int left = 0, right = 0; right < s.size(); right++)
        {
            char in = s[right];
            hash2[in]++;
            if (hash2[in] == hash1[in])
            {
                count++;
            }
            while (count == m)
            {
                if (right - left + 1 < len)
                {
                    len = right - left + 1;
                    pos = left;
                }
                char out = s[left];
                if (hash2[out] == hash1[out])
                {
                    count--;
                }
                hash2[out]--;
                left++;
            }
        }
        if (pos == -1)
        {
            return "";
        }
        return s.substr(pos, len);
    }
};