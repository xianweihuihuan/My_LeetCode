typedef struct ListNode ls;
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void adjustdown(int *arr, int parent, int n)
{
    int child = parent * 2 + 1;
    while (child < n)
    {
        if (child + 1 < n && arr[child] < arr[child + 1])
        {
            child++;
        }
        if (arr[child] > arr[parent])
        {
            swap(&arr[child], &arr[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void heapsortdown(int *arr, int n)
{
    int i = (n - 1 - 1) / 2;
    for (i; i >= 0; i--)
    {
        adjustdown(arr, i, n);
    }
    int end = n - 1;
    while (end > 0)
    {
        swap(&arr[0], &arr[end]);
        adjustdown(arr, 0, end);
        end--;
    }
}

struct ListNode *sortList(struct ListNode *head)
{
    int arr[100000] = {0};
    int len = 0;
    ls *pcur = head;
    while (pcur != NULL)
    {
        arr[len++] = pcur->val;
        pcur = pcur->next;
    }
    heapsortdown(arr, len);
    pcur = head;
    len = 0;
    while (pcur != NULL)
    {
        pcur->val = arr[len++];
        pcur = pcur->next;
    }
    return head;
}