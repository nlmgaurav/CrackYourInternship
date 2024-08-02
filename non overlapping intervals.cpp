class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int ans = -1;
        sort(intervals.begin(), intervals.end(), comp);
        vector<int> prev = intervals[0];
        for (vector<int> cur : intervals)
        {
            if (prev[1] > cur[0])
                ans++;
            else
                prev = cur;
        }
        return ans;
    }
};