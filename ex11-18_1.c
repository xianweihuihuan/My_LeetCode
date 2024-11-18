typedef struct ListNode ls;
struct ListNode *reverseBetween(struct ListNode *head, int left, int right)
{
    if (right == left)
    {
        return head;
    }
    int l = left - 1;
    int r = right - 1;
    ls *le = head;
    ls *ri = head;
    ls *lel = NULL;
    while (l--)
    {
        lel = le;
        le = le->next;
    }
    while (r--)
    {
        ri = ri->next;
    }
    if (left == 1)
    {
        ls *pcur = head;
        ls *prev = NULL;
        ls *tmp = pcur->next;
        while (left < right)
        {
            prev = pcur;
            pcur = tmp;
            tmp = pcur->next;
            pcur->next = prev;
            left++;
        }
        head->next = tmp;
        head = ri;
        return head;
    }
    else
    {
        ls *pcur = le;
        ls *prev = NULL;
        ls *tmp = pcur->next;
        while (left < right)
        {
            prev = pcur;
            pcur = tmp;
            tmp = pcur->next;
            pcur->next = prev;
            left++;
        }
        lel->next = ri;
        le->next = tmp;
    }
    return head;
}