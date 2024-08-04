void rearrange(Node **head, Node *last)
{
    if (!last)
        return;
    // Recursive call
    rearrange(head, last->next);
    // (*head)->next will be set to NULL after
    // rearrangement. Need not do any operation further Just
    // return here to come out of recursion
    if (!(*head)->next)
        return;

    // Rearrange the list until both head and last meet or
    // next to each other.
    if ((*head) != last && (*head)->next != last)
    {
        Node *tmp = (*head)->next;
        (*head)->next = last;
        last->next = tmp;
        *head = tmp;
    }
    else
    {
        if ((*head) != last)
            *head = (*head)->next;
        (*head)->next = NULL;
    }
}