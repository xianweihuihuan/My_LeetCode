typedef struct ListNode ls;
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head==NULL){
        return head;
    }
    ls* tail = head;
    int i = 1;//统计节点个数
    while(tail->next!=NULL){
        tail = tail->next;
        i++;
    }
    if(head==tail){
        return head;
    }
    k%=i;//优化，提高效率
    while(k--){
        ls*pcur = head;
        while(pcur->next!=NULL&&pcur->next!=tail){
            pcur = pcur->next;
        }
        pcur->next = NULL;
        tail ->next = head;
        head = tail;
        tail = pcur;
    }
    return head;
}