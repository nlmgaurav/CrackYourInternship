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
/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
          stack<int>s1,s2;
        while(l1!=NULL){
            s1.push(l1->val);
            l1=l1->next;
        }
         while(l2!=NULL){
            s2.push(l2->val);
            l2=l2->next;
        }
        ListNode* dummy=new ListNode(0);
        
       
        int carry=0;
        while(!s1.empty() || !s2.empty() || carry){
           int first=0,second=0;
            if(!s1.empty()){
               first= s1.top();
                s1.pop();
            }
           if(!s2.empty()){
               second= s2.top();
                s2.pop();
            }
            int sum=carry+first+second;
            carry=sum/10;
            ListNode* attach=new ListNode(sum%10); //bcz we can only attach <10 so thats why modulo of 10
            attach->next=dummy->next;
            dummy->next=attach;
        }
        return dummy->next;
     
    }
};*/
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* cur=head,*prev=NULL,*nxt;
        while(cur!=NULL){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
    }
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       l1=reverse(l1);
       l2=reverse(l2);
       ListNode*dummy=new ListNode();
       ListNode* temp=dummy;
       int carry=0;
       while(l1!=NULL || l2!=NULL || carry){
           int sum=0;
           
           if(l1!=NULL){
               sum+=l1->val;
               l1=l1->next;
           }
           if(l2!=NULL){
               sum+=l2->val;
               l2=l2->next;
           }
           sum+=carry;
           carry=sum/10;
           ListNode* help=new ListNode(sum%10);
           temp->next=help;
           temp=temp->next;
       }
       return (reverse(dummy->next));
    }
};