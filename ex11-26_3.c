typedef struct ListNode ls;
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    ls *pcur = head;
    int count = 1;
    while (pcur->next != NULL)
    {
        pcur = pcur->next;
        count++;
    }
    if (count == 1)
    {
        return NULL;
    }
    int tmp = count - n;
    pcur = head;
    ls *prev = NULL;
    ls *tail = pcur->next;
    while (tmp--)
    {
        prev = pcur;
        pcur = tail;
        tail = pcur->next;
    }
    if (pcur == head)
    {
        free(head);
        head = tail;
        return head;
    }
    free(pcur);
    prev->next = tail;
    return head;
}