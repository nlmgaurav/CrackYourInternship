bool helper(int src, vector<bool> &vis, vector<int> adj[], int parent)
{
    vis[src] = true;
    for (auto nbr : adj[src])
    {
        if (!vis[nbr])
        {
            if (helper(nbr, vis, adj, src))
                return true;
        }
        else if (nbr != parent)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{

    vector<bool> vis(V + 1, false);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (helper(i, vis, adj, -1))
                return true;
        }
    }

    return false;
}