int lengthOfLongestSubstring(char *s)
{
    int ans = 0;
    int shall[200] = {0};
    int i = 0;
    int j = 0;
    int tmp = 0;
    for (j; j < strlen(s); j++)
    {
        shall[s[j]]++;
        while (shall[s[j]] > 1)
        {
            shall[s[i]]--;
            i++;
        }
        tmp = j - i + 1;
        ans = (tmp > ans) ? tmp : ans;
    }
    return ans;
}