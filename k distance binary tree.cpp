
class Solution {
public:
    
    /* approach
    
    in first bfs traversal we are marking parent of every element
    Node->parent
    
    in second traversal we are starting from
    target node and if its left right child has not 
    visited so were visiting and
    and we will do this thing until we have not pushed 
    distance k all node
    at the end we will make our answer from queue ele*/
    
    
    
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            if(cur->left)
            {
                parent[cur->left]=cur;
                q.push(cur->left);
            }
            if(cur->right)
            {
                parent[cur->right]=cur;
                q.push(cur->right);
            }
           
        }
        unordered_map<TreeNode*,bool>vis;
        q.push(target);
        vis[target]=true;
        int cnt=0;
        while(!q.empty())
        {
            int sz=q.size();
            if(cnt++==k)break;
            for(int i=0;i<sz;i++)
            {
               TreeNode* cur=q.front();
                q.pop();
                if(cur->left && !vis[cur->left])
                {
                    q.push(cur->left);
                    vis[cur->left]=true;
                }
                if(cur->right && !vis[cur->right])
                {
                    q.push(cur->right);
                    vis[cur->right]=true;
                }
                if(parent[cur] && !vis[parent[cur]]){
                    q.push(parent[cur]);
                    vis[parent[cur]]=true;
                }
            }
            
        }
        
        
        //answer
        
        
        vector<int>ans;
        
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
        
        
        
    }
};