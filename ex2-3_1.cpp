class Solution
{
public:
    int getSum(int a, int b)
    {
        while (a != 0)
        {
            unsigned int carry = (unsigned int)(a & b) << 1;
            b = a ^ b;
            a = carry;
        }
        return b;
    }
};