
class Solution {
public:
    int ans=0;
    void help(TreeNode* root,bool isLeft)
    {
         if(!root)return;
        if(isLeft && !root->left && !root->right)ans+=root->val;
        help(root->left,true);
        help(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)return 0;
        help(root,false);
        return ans;
    }
};