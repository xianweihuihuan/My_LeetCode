class Solution
{
public:
    int hIndex(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int n = right + 1;
        if (nums[right] == 0)
        {
            return 0;
        }
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= n - mid)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return n - left;
    }
};