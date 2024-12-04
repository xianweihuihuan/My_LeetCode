int strStr(char *haystack, char *needle)
{
    int sz1 = strlen(haystack);
    int sz2 = strlen(needle);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < sz1)
    {
        j = i;
        k = 0;
        while (j < sz1 && k < sz2 && haystack[j] == needle[k])
        {
            j++;
            k++;
        }
        if (k == sz2)
        {
            return i;
        }
        i++;
    }
    return -1;
}