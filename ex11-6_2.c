int divide(int dividend, int divisor)
{
    if (dividend == -2147483648 && divisor == -1)
    {
        return 2147483647;
    }
    if (dividend == -2147483648 && divisor == 1)
    {
        return -2147483648;
    }
    int sp = 0;
    long long a = dividend;
    long long b = divisor;
    if (dividend == 0)
    {
        return 0;
    }
    if (divisor == 1)
    {
        return dividend;
    }
    if (divisor == -1)
    {
        return -dividend;
    }
    if (dividend > 0 && divisor < 0)
    {
        a = -dividend;
        sp = 1;
    }
    else if (dividend < 0 && divisor > 0)
    {
        b = -divisor;
        sp = 1;
    }
    else if (dividend > 0 && divisor > 0)
    {
        a = -dividend;
        b = -divisor;
        sp = 0;
    }
    int an = 0;
    long tmp = 0;
    int pc = 0;
    while (a < 0)
    {
        tmp += b;
        pc++;
        an += pc;
        a -= tmp;
    }
    while (a > 0)
    {
        a += b;
        an--;
    }
    if (sp == 1)
    {
        return -an;
    }

    return an;
}