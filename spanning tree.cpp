class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<bool>vis(V+1,false);
        int ans=0;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto cur=pq.top();
            pq.pop();
            int x=cur.second;
            int wt=cur.first;
            if(vis[x])continue;
            ans+=wt;
            vis[x]=true;
            for(auto y:adj[x])
            {
                if(vis[y[0]]==false)pq.push({y[1],y[0]});
            }
        }
        return ans;
    }
};