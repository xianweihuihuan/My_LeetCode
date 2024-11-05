int reverse(int x)
{
    long long he = 0; // 防止反转后的数越界
    if (x >= 0)
    {
        int i = 0;
        long b[100];
        while (x / 10)
        {
            b[i] = x % 10;
            i++;
            x /= 10;
        }
        b[i++] = x % 10;
        int y = 0;
        while (y < i)
        {
            for (int j = 0; j < i - 1 - y; j++)
            {
                b[y] *= 10;
            }
            he += b[y];
            y++;
        }
    }
    else
    {
        long long a = -(x + 1);
        a++;
        // 防止取相反数后越界，int的范围
        int i = 0;
        long long b[100];
        while (a / 10)
        {
            b[i] = a % 10;
            i++;
            a /= 10;
        }
        b[i++] = a % 10;
        int y = 0;
        while (y < i)
        {
            for (int j = 0; j < i - 1 - y; j++)
            {
                b[y] *= 10;
            }
            he -= b[y];
            y++;
        }
    }
    if (he > 2147483647 || he < -2147483648)
    {
        return 0;
    }
    return he;
}