class Solution
{
    int empty = 1;

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
                else if (grid[i][j] == 0)
                    empty++;
            }
        }
        int res = 0;
        dfs(grid, x, y, n, m, res);
        return res;
    }
    void dfs(vector<vector<int>> &v, int i, int j, int n, int m, int &c)
    {
        if (i < 0 || j < 0 || i > n - 1 || j > m - 1 || v[i][j] < 0)
            return;
        if (v[i][j] == 2)
        {
            if (empty == 0)
                c++;
            return;
        }
        v[i][j] = -2;
        empty--;
        dfs(v, i - 1, j, n, m, c);
        dfs(v, i + 1, j, n, m, c);
        dfs(v, i, j + 1, n, m, c);
        dfs(v, i, j - 1, n, m, c);
        v[i][j] = 0;
        empty++;
    }
};