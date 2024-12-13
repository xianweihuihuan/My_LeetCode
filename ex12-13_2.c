void duplicateZeros(int *arr, int arrSize)
{
    int cur = 0, det = -1;
    while (cur < arrSize)
    {
        if (arr[cur] == 0)
        {
            det += 2;
        }
        else
        {
            det++;
        }
        if (det >= arrSize - 1)
        {
            break;
        }
        cur++;
    }
    if (det == arrSize)
    {
        arr[arrSize - 1] = 0;
        cur--;
        det -= 2;
    }
    while (cur >= 0)
    {
        if (arr[cur] == 0)
        {
            arr[det--] = 0;
            arr[det--] = 0;
        }
        else
        {
            arr[det--] = arr[cur];
        }
        cur--;
    }
}