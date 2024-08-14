  void helper(TreeNode* root,int level,vector<int>&ans)
    {
        if(!root)return;
         if(level==ans.size())ans.push_back(root->val);
        helper(root->right,level+1,ans);
        helper(root->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        helper(root,0,ans);
        return ans;
    }