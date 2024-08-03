bool dfs(int src, vector<int> &vis, vector<int> &curPath, vector<int> adj[])
{
    vis[src] = 1;
    curPath[src] = 1;
    for (int nbr : adj[src])
    {
        if (!vis[nbr])
        {
            if (dfs(nbr, vis, curPath, adj))
                return true;
        }
        else if (curPath[nbr] == 1)
            return true;
    }
    curPath[src] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<int> vis(V, 0);
    vector<int> curPath(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis, curPath, adj))
                return true;
        }
    }
    return false;
}