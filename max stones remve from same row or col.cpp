class Solution {
public:

   // particular index(row,col) se kitne aur (idx(row,col)) pr jaskte hai
   // vhi hmara answer hoga

int dfs(int idx,vector<vector<int>>&stones,vector<int>&vis,int &n)
{
    vis[idx]=true;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i] && (stones[i][0]==stones[idx][0] || stones[i][1]==stones[idx][1])){
            ans+=1+dfs(i,stones,vis,n);
        }
    }
    return ans;
}


    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i])continue;
            ans+=dfs(i,stones,vis,n);
        }
        return ans;
    }
};