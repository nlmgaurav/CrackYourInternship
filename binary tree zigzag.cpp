
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int count=0;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>level(sz);
           /* reverse method
           while(sz--)
            {
                auto cur=q.front();
                q.pop();
                level.push_back(cur->val);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            if(count%2==0)reverse(level.begin(),level.end());//only reversing even levels
                ans.push_back(level);
            count++;*/
            
            //without reverse
            // keeping track of odd and even level with the help of count variable and using Level Order Traversal
    // if count is odd, then storing values in level in reverse order
            for(int i=0;i<sz;i++)
            {
                auto cur=q.front();
                q.pop();
                if(count%2==0)level[i]=cur->val;//even simply push in ans
                else //odd then push ans in reverse order
                    level[sz-i-1]=cur->val;
                    if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            ans.push_back(level);
            count++;
            
            
        }
        return ans;
    }
};