class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> s1;
        for (const auto &e : s)
               
            {
                if (e == '(')
                {
                    s1.push(')');
                }
                else if (e == '{')
                {
                    s1.push('}');
                }
                else if (e == '[')
                {
                    s1.push(']');
                }
                else
                {
                    if (!(s1.empty()) && e == s1.top())
                    {
                        s1.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        return s1.empty();
    }
};