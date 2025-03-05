class Solution
{
public:
    string countAndSay(int n)
    {
        string ret = "1";
        for (int i = 1; i < n; i++)
        {
            int left = 0;
            int right = 0;
            string tmp;
            for (; right < ret.size();)
            {
                while (right < ret.size() && ret[right] == ret[left])
                {
                    right++;
                }
                tmp += to_string(right - left) + ret[left];
                left = right;
            }
            ret = tmp;
        }
        return ret;
    }
};