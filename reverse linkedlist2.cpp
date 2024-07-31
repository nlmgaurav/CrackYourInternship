/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* rev(ListNode* head)
{
    ListNode* cur=head,*prev=NULL,*n;
    while(cur){
        n=cur->next;
        cur->next=prev;
        prev=cur;
        cur=n;
    }
    return prev;
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head)return head;
        ListNode* cur=head;
        for(int i=0;i<left-1;i++)cur=cur->next;
        ListNode* temp=cur ;
        for(int i=left;i<right;i++)temp=temp->next;
        ListNode* rest=temp->next;
        temp->next=NULL;
        ListNode* rev=reverse(cur)

    }
};