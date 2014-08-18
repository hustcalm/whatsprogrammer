void reverse(Element* head) 
{
    Element* prev, middle;
    middle = NULL;
    Element* node = head;
    while(node) {
        pre = middle;
        middle = node;
        node = node->next;
        middle->next = pre;
    }

    return middle;
}
