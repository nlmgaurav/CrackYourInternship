Node *Reverse(Node *head)
{
    Node *prev = NULL;
    while (head)
    {
        Node *ahead = head->next;
        head->next = prev;
        prev = head;
        head = ahead;
    }
    return prev;
}
pair<Node *, bool> SubtractLL(Node *head1, Node *head2)
{
    Node *ans = new Node(-1);
    Node *curr = ans;
    int carry = 0;
    while (head1 && head2)
    {
        int first = head1->data;
        if (carry == 1)
        {
            if (first == 0)
            {
                first = 9;
                carry = 1;
            }
            else
            {
                first--;
                carry = 0;
            }
        }
        int second = head2->data;
        if (first < second)
        {
            first += 10;
            carry = 1;
        }
        curr->next = new Node(first - second);
        curr = curr->next;
        head1 = head1->next;
        head2 = head2->next;
    }
    while (head1)
    {
        int first = head1->data;
        if (carry == 1)
        {
            if (first == 0)
            {
                carry = 1;
                first = 9;
            }
            else
            {
                carry = 0;
                first--;
            }
        }
        curr->next = new Node(first);
        curr = curr->next;
        head1 = head1->next;
    }
    if (carry == 1)
        return {NULL, false};
    while (head2)
    {
        if (head2->data != 0)
            return {NULL, false};
        head2 = head2->next;
    }
    curr->next = NULL;
    return {ans->next, true};
}
Node *subLinkedList(Node *head1, Node *head2)
{
    head1 = Reverse(head1);
    head2 = Reverse(head2);
    pair<Node *, bool> one = SubtractLL(head1, head2);
    pair<Node *, bool> two = SubtractLL(head2, head1);

    if (one.second == true)
    {
        Node *temp1 = Reverse(one.first);
        while (temp1->next && temp1->data == 0)
            temp1 = temp1->next;
        return temp1;
    }
    if (two.second == true)
    {
        Node *temp2 = Reverse(two.first);
        while (temp2->next && temp2->data == 0)
            temp2 = temp2->next;
        return temp2;
    }
    return NULL;
}