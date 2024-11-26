void sortColors(int *nums, int numsSize)
{
    int arr[3] = {0};
    for (int i = 0; i < numsSize; i++)
    {
        arr[nums[i]]++;
    }
    int len = 0;
    for (int i = 0; i < 3; i++)
    {
        while (arr[i] > 0)
        {
            nums[len++] = i;
            arr[i]--;
        }
    }
}