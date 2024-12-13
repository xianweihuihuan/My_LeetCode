int maxArea(int *height, int heightSize)
{
    int left = 0;
    int right = heightSize - 1;
    int max = 0;
    while (left < right)
    {
        int h = (height[left] < height[right]) ? height[left] : height[right];
        int S = h * (right - left);
        if (S > max)
        {
            max = S;
        }
        if (height[left] < height[right])
        {
            int tmp = height[left];
            while (left < right && height[left] <= tmp)
            {
                left++;
            }
        }
        else
        {
            int tmp = height[right];
            while (left < right && height[right] <= tmp)
            {
                right--;
            }
        }
    }
    return max;
}