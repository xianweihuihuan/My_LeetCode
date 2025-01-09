class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums[0] < nums[nums.size() - 1])
        {
            return nums[0];
        }
        int left = 0;
        int right = nums.size() - 1;
        int n = right;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[0])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return nums[left];
    }
};