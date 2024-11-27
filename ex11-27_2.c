int findDuplicate(int *nums, int numsSize)
{
    int arr[100010] = {0};
    for (int i = 0; i < numsSize; i++)
    {
        arr[nums[i]]++;
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (arr[i] >= 2)
        {
            return i;
        }
    }
    return -1;
}
