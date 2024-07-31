/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur=head;
        while(cur)
        {
            if(cur->child){
                Node* bchha=cur->child;
                Node* ryt=cur->next;
                cur->next=bchha;
                
                bchha->prev=cur;
                cur->child=NULL;
                while(bchha->next){
                    bchha=bchha->next;
                }
                bchha->next=ryt;
                if(ryt){
                    ryt->prev=bchha;
                }
            }
            cur=cur->next;
        }
            
        return head;
    }
};