class Solution {
public:
// approach   if number of connection is greater or equal to n-1 then we can make graph connected
// else we cant
// so for this we will count how many components are there and return componets-1
// simple dfs

    void dfs(int i,vector<vector<int>>&adj,vector<int>&vis)
    {
        vis[i]=1;
        for(auto j:adj[i]){
            if(!vis[j])dfs(j,adj,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int sz=connections.size();
        if(sz<n-1)return -1;
        vector<vector<int>>adj(n+1);
        vector<int>vis(n+1,0);
        for(auto e:connections)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int components=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]){
                dfs(i,adj,vis);
                components++;
            }
        }
        return components-1;
    }
};