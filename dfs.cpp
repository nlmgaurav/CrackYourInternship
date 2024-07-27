class Solution {
  public:
    // Functiint src,vector<boolon to return a list containing the DFS traversal of the graph.
    void dfs(int src,vector<bool>&vis,vector<int>&ans,vector<int>adj[])
    {
        vis[src]=true;
        
        ans.push_back(src);
        for(int nbr:adj[src])
        {
            if(!vis[nbr])dfs(nbr,vis,ans,adj);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])dfs(i,vis,ans,adj);
        }
        return ans;
    }
};