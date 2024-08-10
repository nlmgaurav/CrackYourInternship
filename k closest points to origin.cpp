class Solution
{
public:
    // we will maintain maxheap and store
    // (1,3)===> (distance,(1,3))
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, pair<int, int>>> maxh;

        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            // pushing x^2 + y^2
            maxh.push({points[i][0] * points[i][0] + points[i][1] * points[i][1],
                       {points[i][0], points[i][1]}});
            // we have maxheap so maximum distance points are at top of
            // heap so we will remove them
            if (maxh.size() > k)
            {
                maxh.pop();
            }
        }

        vector<vector<int>> ans;
        while (maxh.size() > 0)
        {
            vector<int> res;
            res.push_back(maxh.top().second.first);
            res.push_back(maxh.top().second.second);
            ans.push_back(res);
            maxh.pop();
        }
        return ans;
    }
};