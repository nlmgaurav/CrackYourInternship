

bool issafe(int &node, int &n, int &newcolor, vector<int> &color, bool graph[101][101])
{
    for (int k = 0; k < n; k++)
    {
        if (graph[node][k])
        {
            if (color[k] == newcolor)
            {
                return false;
            }
        }
    }
    return true;
}
bool iscolor(int node, int &m, int &n, vector<int> &color, bool graph[101][101])
{
    if (node == n)
    {
        return true;
    }
    for (int col = 1; col <= m; col++)
    {
        if (issafe(node, n, col, color, graph))
        {
            color[node] = col;
            if (iscolor(node + 1, m, n, color, graph))
            {
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n, 0);
    return iscolor(0, m, n, color, graph);
}
