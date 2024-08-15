
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        if(!root)return 0;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int sz=q.size();
            ans=max(ans,q.back().second-q.front().second+1);
            while(sz--){
                auto cur=q.front();
                q.pop();
                long long int idx=cur.second;
                if(cur.first->left)q.push({cur.first->left,2*idx+1});
                if(cur.first->right)q.push({cur.first->right,2*idx+2});
            }
        }
        return ans;
    }
};