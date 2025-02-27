class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        s += ' ';
        auto begin = s.begin();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                reverse(begin, s.begin() + i);
                begin = s.begin() + i + 1;
            }
        }
        s.pop_back();
        auto i = s.begin();
        while (i != s.end())
        {
            if (*i == ' ')
            {
                if (*(i + 1) == ' ')
                {
                    i = s.erase(i);
                    continue;
                }
                if (i == s.begin())
                {
                    i = s.erase(i);
                    continue;
                }
                if (i == s.end() - 1)
                {
                    i = s.erase(i);
                    continue;
                }
            }
            i++;
        }
        return s;
    }
};