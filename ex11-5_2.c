bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    int b[20];
    int i = 0;
    while (x / 10)
    {
        b[i++] = x % 10;
        x /= 10;
    }
    b[i++] = x % 10;
    int left = 0;
    int right = i - 1;
    while (left < i)
    {
        if (b[left] != b[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}