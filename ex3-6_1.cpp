class Solution
{
public:
    string convert(string s, int n)
    {
        if (n == 1)
        {
            return s;
        }
        string ret;
        int d = n * 2 - 2;
        int sz = s.size();
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == n - 1)
            {
                for (int j = i; j < sz; j += d)
                {
                    ret += s[j];
                }
            }
            else
            {
                for (int j = i, k = d - j; j < sz || k < sz; k += d, j += d)
                {
                    if (j < sz)
                    {
                        ret += s[j];
                    }
                    if (k < sz)
                    {
                        ret += s[k];
                    }
                }
            }
        }
        return ret;
    }
};