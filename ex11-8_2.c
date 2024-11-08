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
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            answer *= x; // 如果指数是奇数(即此时最右侧二进制位为1)，乘上当前的底数x
        }
        x *= x; // 将底数平方，以对应下指数二进制位的底数
        b /= 2; // 指数除以 2，相当于 b>>=1;
    }
    if (sp == 1)
    {
        double newn = 1.0 / answer;
        return newn;
    }
    return answer;
}
// 二进制快速幂：将指数转换为二进制的方式，如果对应二进制位为1,则将该为对应的指数幂乘上，如果为0,则继续右移指数，并将底数平方以对应指数的下一二进制位，
//
// 指数：    1       0       1       1       0       1       1       1
// 对应底数  x^128   x^64    x^32    x^16    x^8     x^4     x^2     x