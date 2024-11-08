double myPow(double x, int n)
{
    double answer = 1.0;
    long long b = n;
    int sp = 0;
    if (n == 0)
    {
        return 1;
    }
    if (x == 1.0)
    {
        return 1.0;
    }
    if (n < 0)
    {
        b = -b;
        sp = 1;
    }
    else
    {
        b = b;
    }
    if (x == -1.0 && b % 2 == 0)
    {
        return 1.0;
    }
    if (x == -1.0 && b % 2 == 1)
    {
        return -1.0;
    }
    long long c = 0;
    c = b / 3;
    double tmp = x * x * x;
    for (int i = 0; i < c; i++)
    {
        answer *= tmp;
    }
    if (b % 3 == 2)
    {
        answer *= x;
        answer *= x;
    }
    else if (b % 3 == 1)
    {
        answer *= x;
    }
    if (sp == 1)
    {
        double newn = 1.0 / answer;
        return newn;
    }
    return answer;
}