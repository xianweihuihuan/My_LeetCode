int num(int n)
{
    int ans = 0;
    while (n > 0)
    {
        int tmp = n % 10;
        ans += (tmp * tmp);
        n /= 10;
    }
    return ans;
}
bool isHappy(int n)
{
    int slow = n;
    int fast = num(n);
    while (slow != fast)
    {
        slow = num(slow);
        fast = num(num(fast));
    }
    return slow == 1;
}