/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:

      Node* reverse(Node* head){
        Node* cur=head,*prev=NULL,*nxt;
        while(cur!=NULL){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        head=reverse(head);
        Node* cur=head;
        Node* prev=head;
        int msf=head->data;
        head=head->next;
        while(head)
        {
            if(head->data>=msf){
                msf=head->data;
                prev=head;
                head=head->next;
            }else
            {
                prev->next=head->next;
                head=prev->next;
            }
        }
        head=reverse(cur);
        return head;
    }
    
};
   