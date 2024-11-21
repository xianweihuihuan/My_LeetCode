#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
    int val;
    int password;
    struct node* next;
} node;
node* buynode(int n)
{

    //printf("%d", sizeof(node));
    node* tmp = (node*)malloc(sizeof(node));
    if (tmp == NULL)
    {
        perror("malloc failed");
        exit(1);
    }
    tmp->next = NULL;
    tmp->val = n;
}
bool empty(node* head)
{
    if (head == NULL) {
        return true;
    }
    return false;
}
void delet(node** head, node* n, node* tail)
{
    if (*head == tail)
    {
        free(*head);
        *head = tail = NULL;
        return;
    }
    node* pcur = *head;
    node* prev = NULL;
    node* ptail = pcur->next;
    if (*head == n)
    {
        
        ptail = (*head)->next;
        free(*head);
        *head = ptail;
    }
    else
    {
        while (pcur != n)
        {
            prev = pcur;
            pcur = pcur->next;
        }
        prev->next = pcur->next;
        free(pcur);
    }
}
int main()
{
    int n = 0;
    int password = 0;
    scanf("%d %d", &n, &password);
    node* head = NULL;
    node* tail = NULL;
    for (int i = 1; i <= n; i++)
    {
        node* tmp = buynode(i);
        if (head == NULL)
        {
            head = tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
        scanf("%d", &(tmp->password));
    }
    node* pcur = head;
    while (!(empty(head)))
    {
        int tmp = password-1;
        while (tmp--) {
            if (pcur == NULL) pcur = head;
            pcur = pcur->next;
        }
        if (pcur == NULL) pcur = head;
        printf("%d ", pcur->val);
        node* next = pcur->next;
        password = pcur->password;
        delet(&head, pcur, tail);
        pcur = next;
    }
}