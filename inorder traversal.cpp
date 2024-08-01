
class Solution {
public:
// l root right   morris traversal
/*   go to left then go to it deepest right node make cnnection to root
then go to left and if no left then print it*/
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* cur=root;
        while(cur!=NULL)
        {
            if(cur->left==NULL)
            {
                ans.push_back(cur->val);
                cur=cur->right;
            }else
            {
                TreeNode* leftChild=cur->left;
                while(leftChild->right!=NULL)leftChild=leftChild->right;
                // making connection from deepest right to rot
                leftChild->right=cur;
                // delteing cur->left connection
                TreeNode*temp=cur;
                cur=cur->left;
                temp->left=NULL;
            }
        }
return ans;
    }
};