bool help(TreeNode* root,long mn,long mx)
{
    if(!root)return true;
    if(root->val>mn && root->val<mx)return help(root->left,mn,root->val) && help(root->right,root->val,mx);
    return false;
}
    bool isValidBST(TreeNode* root) {
        return help(root,LONG_MIN,LONG_MAX);

    }