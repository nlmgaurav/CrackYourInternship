class Solution {
public:
    ListNode* reverseList(ListNode* head) {
          ListNode *c=head;
        ListNode* p=NULL;
        ListNode* n;
        while(c!=NULL){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        
        }
        head=p;
        return p;
    }
};