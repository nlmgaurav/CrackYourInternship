int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    // Code here
    pair<int, int> src = {KnightPos[0] - 1, KnightPos[1] - 1};
    pair<int, int> dest = {TargetPos[0] - 1, TargetPos[1] - 1};
    vector<vector<bool>> vis(N, vector<bool>(N, false));
    int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
    int dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};
    queue<pair<int, int>> q;
    int steps = 0;
    q.push(src);
    vis[src.first][src.second] = 1;
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            pair<int, int> cur = q.front();
            q.pop();
            if (cur == dest)
            {
                return steps;
            }
            // making recursive calls in 8 direction
            for (int i = 0; i < 8; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= N - 1 && !vis[nx][ny])
                {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        steps++;
    }
    return -1;
}