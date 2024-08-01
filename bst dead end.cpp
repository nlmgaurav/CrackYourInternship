/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
     bool solve(Node* root,int ul, int ll){
        if(root == NULL){
            return true;
        }

        if(root->left == NULL && root->right == NULL){
            return ul-root->data > 1 || root->data - ll > 1;
        }

       return  solve(root->left,root->data,ll) &&  solve(root->right,ul,root->data);
       
    }
  public:
    bool isDeadEnd(Node *root)
    {
        int ul = INT_MAX;
        int ll = 0;
       bool ans =  solve(root,ul,ll);
       return !ans;
    }


};