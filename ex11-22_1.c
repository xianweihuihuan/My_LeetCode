int removeDuplicates(int *nums, int numsSize)
{
    int slow = 0;
    int fast = 0;
    int n = 1;
    while (fast < numsSize)
    {
        if (nums[slow] != nums[fast])
        {
            nums[++slow] = nums[fast++];
            n++;
        }
        else
        {
            fast++;
        }
    }
    return n;
}
int removeDuplicates(int *nums, int numsSize)
{
    int arr[20002] = {0};
    for (int i = 0; i < numsSize; i++)
    {
        if (arr[nums[i] + 10000] >= 2)
        {
            continue;
        }
        else
        {
            arr[nums[i] + 10000]++;
        }
    }
    int n = 0;
    for (int i = 0; i <= 20001; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        else
        {
            while (arr[i] != 0)
            {
                nums[n++] = i - 10000;
                arr[i]--;
            }
        }
    }
    return n;
}