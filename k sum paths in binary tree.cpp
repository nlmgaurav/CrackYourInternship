 void help(Node* root,int k,int prev,int &ans,unordered_map<int,int>&mp)
  {
      if(!root)return;
      int curSum=root->data+prev;
      if(mp.find(curSum-k)!=mp.end())ans+=mp[curSum-k];
      if(curSum==k)ans++;
      mp[curSum]++;
      help(root->left,k,curSum,ans,mp);
         help(root->right,k,curSum,ans,mp);
         // backtracking
         mp[curSum]--;
  }
    int sumK(Node *root,int k)
    {
        // code here 
        int ans=0;
        unordered_map<int,int>mp;  // this stores sum->count
        help(root,k,0,ans,mp);
        return ans;
    }