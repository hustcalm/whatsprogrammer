typedef struct node
{
    ElemType data;
    struct node *prior
    struct node *next;
}list;

list *reverselist(list *head)
{
    if ((NULL == head) || (NULL == head->next))
    {
        return head;
    }
    list *p1=head, *p2=p1->next, *p3=NULL;
    p1->next = NULL;
    while (p2)
    {
        p3 = p2->next;
        p2->next = p1;
        p1->prior = p2;
        p1 = p2;
        p2 = p3;
    }
    head = p1;
    return head;
}
