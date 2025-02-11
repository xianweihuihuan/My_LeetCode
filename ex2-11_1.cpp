class Solution
{
public:
    bool isUnique(string astr)
    {
        if (astr.size() > 26)
        {
            return false;
        }
        int bitmap = 0;
        for (auto i : astr)
        {
            int e = i - 'a';
            if ((bitmap >> e) & 1  == 1)
            {
                return false;
            }
            bitmap |= (1 << e);
        }
        return true;
    }
};