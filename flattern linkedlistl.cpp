  void flatten(TreeNode* root) {
          if(root==NULL){return ;}
         TreeNode* curr=root;
         while(curr!=NULL)
         {
             if(curr->left!=NULL)
             {
                 TreeNode* next=curr->left;
                 while(next->right!=NULL)
                 {
                     next=next->right;
                 }
                 next->right=curr->right;
                 curr->right=curr->left;
                 curr->left=NULL;
             }
        
        curr=curr->right; 
         }
    }