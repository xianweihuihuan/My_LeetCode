int minSubArrayLen(int target, int *nums, int numsSize)
{
    int i = 0;
    int sum = 0;
    int ans = 100000;
    int he = 0;
    for (int k = 0; k < numsSize; k++)
    {
        he += nums[k];
    }
    if (he < target)
    {
        return 0;
    }
    for (int j = 0; j < numsSize; j++)
    {
        sum += nums[j];
        while (sum >= target)
        {
            int tmp = j - i + 1;
            ans = (ans < tmp) ? ans : tmp;
            sum -= nums[i];
            i++;
        }
    }
    return ans;
}   