class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
          vector<int>ans;
        vector<bool>vis(V+1,false);
        queue<int>q;
        q.push(0);
        vis[0]=true;
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            for(int nbr:adj[cur]){
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr]=true;
                }
            }
        }
        return ans;
    }
};