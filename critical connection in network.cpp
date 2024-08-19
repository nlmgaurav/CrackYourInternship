class Solution
{
public:
    int timer = 1;
    void dfs(int node, int parent, int tim[], int low[], vector<int> adj[], vector<int> &vis, vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        tim[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (vis[it] == 0)
            {
                dfs(it, node, tim, low, adj, vis, bridges);
                low[node] = min(low[node], low[it]);
                // node---it
                if (low[it] > tim[node])
                    bridges.push_back({it, node});
            }
            else
                low[node] = min(low[node], low[it]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int tim[n];
        int low[n];
        vector<int> vis(n, 0);
        vector<vector<int>> bridges;

        dfs(0, -1, tim, low, adj, vis, bridges);
        return bridges;
    }
};