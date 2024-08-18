// User function Template for C++

class Solution
{
public:
    /*  Function to implement Dijkstra
     *   adj: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int v, vector<vector<int>> adj, int s)
    {
        // Code here

        vector<int> dist(v, 1e8);
        dist[s] = 0;
        for (int i = 0; i < v - 1; i++)
        {
            for (auto x : adj)
            {
                int a = x[0];
                int b = x[1];
                int c = x[2];
                if (dist[a] + c < dist[b])
                {
                    dist[b] = dist[a] + c;
                }
            }
        }
        return dist;
    }
};
making a large island.cpp