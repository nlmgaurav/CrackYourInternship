vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> deg(V, 0);
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
            deg[j]++;
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (deg[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        ans.push_back(cur);
        for (auto nbr : adj[cur])
        {
            deg[nbr]--;
            if (deg[nbr] == 0)
                q.push(nbr);
        }
    }
    return ans;
}