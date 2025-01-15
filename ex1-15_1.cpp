class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> f(n), g(n);
        f[0] = g[n - 1] = 1;
        for (int i = 1; i < n; i++)
        {
            f[i] = f[i - 1] * nums[i - 1];
            g[n - 1 - i] = g[n - i] * nums[n - i];
        }
        vector<int> ret(n);
        for (int i = 0; i < n; i++)
        {
            ret[i] = f[i] * g[i];
        }
        return ret;
    }
};