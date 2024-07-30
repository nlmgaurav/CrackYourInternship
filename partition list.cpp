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
    ListNode* partition(ListNode* head, int x) {
         ListNode* small=new ListNode(0);
         ListNode* high=new ListNode(0);
         ListNode* smallhead=small;
         ListNode* highhead=high;
        while(head!=NULL){
            if(head->val<x){
                //small list
                smallhead->next=head;
                smallhead=smallhead->next;
            }else{
                //high list
                 highhead->next=head;
                highhead=highhead->next;
            }
            head=head->next;
        }
        
        smallhead->next=high->next;
        highhead->next=NULL;
        return small->next;
       
     
    }
};