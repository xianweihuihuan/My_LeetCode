class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> p1(n), p2(n);
        for (int i = 1; i < n; i++)
        {
            p1[i] = p1[i - 1] + nums[i - 1];
            p2[n - 1 - i] = p2[n - i] + nums[n - i];
        }
        for (int i = 0; i < n; i++)
        {
            if (p1[i] == p2[i])
            {
                return i;
            }
        }
        return -1;
    }
};