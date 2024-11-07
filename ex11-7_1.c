char *multiply(char *num1, char *num2)
{
    if (strcmp("0", num1) == 0 || strcmp("0", num2) == 0)
    {
        return "0";
    }
    int sz1 = strlen(num1);
    int sz2 = strlen(num2);
    long long a = 0;
    long long b = 0;
    long long c = 0;
    for (int i = 0; i < sz1; i++)
    {
        c = num1[i] - 48;
        for (int j = 0; j < sz1 - i - 1; j++)
        {
            c *= 10;
        }
        a += c;
    }
    for (int i = 0; i < sz2; i++)
    {
        c = num2[i] - 48;
        for (int j = 0; j < sz2 - i - 1; j++)
        {
            c *= 10;
        }
        b += c;
    }
    long long ans = a * b;
    int sz3 = 0;
    long long tmp = ans;
    char *answer = (char *)malloc(10000);
    while (ans)
    {
        c = ans % 10;
        answer[sz3++] = c + 48;
        ans /= 10;
    }
    int left = 0;
    int right = sz3 - 1;
    while (left < right)
    {
        char a = answer[left];
        answer[left] = answer[right];
        answer[right] = a;
        left++;
        right--;
    }
    answer[sz3] = '\0';
    return answer;
}