// User function Template for C++

class Solution
{
public:
    vector<int> topo(int V, vector<int> adj[])
    {
        vector<int> ans, in(V, 0);
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            for (auto x : adj[i])
            {
                in[x]++;
            }
        }
        for (int i = 0; i < V; i++)
            if (in[i] == 0)
                q.push(i);
        while (q.size())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto x : adj[node])
            {
                in[x]--;
                if (in[x] == 0)
                    q.push(x);
            }
        }
        return ans;
    }
    string findOrder(string dict[], int n, int k)
    {
        string a, b, ans = "";
        vector<int> adj[k];
        for (int i = 0; i < n - 1; i++)
        {
            a = dict[i], b = dict[i + 1];
            for (int ptr = 0; ptr < min(a.size(), b.size()); ptr++)
            {
                if (a[ptr] != b[ptr])
                {
                    adj[a[ptr] - 'a'].push_back(b[ptr] - 'a');
                    break;
                }
            }
        }
        vector<int> topoArray = topo(k, adj);
        for (auto x : topoArray)
        {
            ans += (x + 'a');
        }
        return ans;
    }
};