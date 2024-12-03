char *longestPalindrome(char *s)
{
    int n = strlen(s);
    int start = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int left = i - 1;
        int right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }
        if (right - left - 1 > len)
        {
            len = right - left - 1;
            start = left + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int left = i;
        int right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }
        if (right - left - 1 > len)
        {
            len = right - left - 1;
            start = left + 1;
        }
    }
    s[start + len] = '\0';
    return s + start;
}