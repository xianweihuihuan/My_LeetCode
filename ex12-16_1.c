void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int _quicksort(int *arr, int left, int right)
{
    int key = left;
    left++;
    while (left <= right)
    {
        while (left <= right && arr[right] > arr[key])
        {
            right--;
        }
        while (left <= right && arr[left] < arr[key])
        {
            left++;
        }
        if (left <= right)
        {
            swap(&arr[left++], &arr[right--]);
        }
    }
    swap(&arr[key], &arr[right]);
    return right;
}
void quicksort(int *arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int key = _quicksort(arr, left, right);
    quicksort(arr, left, key - 1);
    quicksort(arr, key + 1, right);
}

int triangleNumber(int *nums, int numsSize)
{
    int ans = 0;
    quicksort(nums, 0, numsSize - 1);
    for (int i = numsSize - 1; i >= 2; i--)
    {
        int left = 0;
        int right = i - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] > nums[i])
            {
                ans += right - left;
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    return ans;
}