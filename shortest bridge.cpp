class Solution {
public:
    // Depth-First Search (DFS) function to mark all cells of the first island as visited.
    void dfs(vector<vector<int>>& A, vector<vector<bool>>& visited, queue<pair<int, int>>& q,
             int i, int j, vector<vector<int>>& dirs) {
        // Base cases for DFS termination:
        // - Out of bounds
        // - Already visited
        // - Cell value is 0 (not part of the island)
        if (i < 0 || j < 0 || i >= A.size() || j >= A[0].size() || visited[i][j] || A[i][j] == 0)
            return;

        // Mark the current cell as visited and add it to the queue
        visited[i][j] = true;
        q.push({i, j});

        // Explore neighboring cells in all four directions (up, down, left, right)
        for (auto& dir : dirs)
            dfs(A, visited, q, i + dir[0], j + dir[1], dirs);
    }

public:
    // Main function to find the shortest bridge between two islands
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // Mark visited cells
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Four directions
        queue<pair<int, int>> q; // BFS queue
        bool found = false; // Flag to indicate if the first island is found

        // Find the first island and initiate DFS from its starting cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    dfs(A, visited, q, i, j, dirs);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        int step = 0; // Initialize step count for BFS

        // Start BFS to find the shortest bridge to the other island
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                auto cur = q.front();
                q.pop();
                for (auto& dir : dirs) {
                    int i = cur.first + dir[0];
                    int j = cur.second + dir[1];
                    if (i >= 0 && j >= 0 && i < m && j < n && !visited[i][j]) {
                        if (A[i][j] == 1) {
                            // Second island found, return the current step count
                            return step;
                        }
                        q.push({i, j});
                        visited[i][j] = true;
                    }
                }
            }
            step++; // Increment step count for each level of BFS
        }

        // If the second island is not found, return -1 to indicate no bridge found
        return -1;
    }
};
