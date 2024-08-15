/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*   here only two nodes are swapped so 
brute force find inorder and sort that and traverse through array and in tree
if cur val not equal to arr value swap them  this tc  nlogn+2n    sc   n 

optimal  : only two swapped are here so   two cases

case 1)   swapped number are adjacent
we will get irregularity at two pos only (prev>cur)

   3 5 8 7 10 15  20 25  (    5,8  ) 

   case2)  not adjacent
   two times irregularity(prev>cur)

   3 25 7 8 10 15 20 5   (25,7)  and   (20,5)

   so what we will do is we will maintain 4 pointers
   first,mid,last,prev 

   if first time we get prev>cur  then  first=prev  and mid==root(cur ele)
   second time  we get   last==root(cur)

   */

class Solution {

   private:
   TreeNode* first;
   TreeNode* mid;
   TreeNode* last;
   TreeNode* prev;

   private:

   void inorder(TreeNode* root)
   {
       if(!root)return;
       inorder(root->left);
       if(prev!=NULL && prev->val>root->val){
           if(first==NULL){
               first=prev;
               mid=root;
           }else{
               last=root;
           }
       }
       prev=root;

       inorder(root->right);
   }



public:
    void recoverTree(TreeNode* root) {
        first=NULL,mid=NULL,last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)swap(first->val,last->val);

       else if(first && mid)swap(first->val,mid->val);
    }
};