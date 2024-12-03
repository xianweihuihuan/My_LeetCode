typedef struct ListNode ls;
void reorderList(struct ListNode *head)
{
    int tmp[50000] = {0};
    ls *prev = head;
    int n = 0;
    while (prev != NULL)
    {
        tmp[n++] = prev->val;
        prev = prev->next;
    }
    int left = 0;
    int right = n - 1;
    int count = 1;
    ls *pcur = head;
    while (left <= right)
    {
        if (count % 2 == 0)
        {
            pcur->val = tmp[right--];
            pcur = pcur->next;
            count++;
        }
        else
        {
            pcur->val = tmp[left++];
            pcur = pcur->next;
            count++;
        }
    }
}