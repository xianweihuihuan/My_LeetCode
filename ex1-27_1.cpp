class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *newhead = nullptr;
        Node *newtial = nullptr;
        map<Node *, Node *> has;
        Node *cur = head;
        while (cur)
        {
            if (newtial == nullptr)
            {
                newhead = newtial = new Node(cur->val);
            }
            else
            {
                newtial->next = new Node(cur->val);
                newtial = newtial->next;
            }
            has[cur] = newtial;
            cur = cur->next;
        }
        cur = head;
        while (cur)
        {
            if (cur->random == nullptr)
            {
                has[cur]->random = nullptr;
            }
            else
            {
                has[cur]->random = has[cur->random];
            }
            cur = cur->next;
        }
        return newhead;
    }
};