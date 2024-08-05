class Solution
{
public:
    bool dfs(int node, vector<int> *adj, int *color)
    {
        for (auto adjacent : adj[node])
        {
            if (color[adjacent] == 0)
            {
                color[adjacent] = (color[node] == 1) ? 2 : 1;
                bool bipartite = dfs(adjacent, adj, color);
                if (!bipartite)
                    return false;
            }
            else if (color[adjacent] == color[node])
                return false;
        }
        return true;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        // 1 2 colouring will be done
        int color[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (color[i] == 0)
            {
                color[i] = 1;
                if (!dfs(i, adj, color))
                    return false;
            }
        }
        return true;
    }
};