class Solution
{
public:
    // memoisation
    int help(int i, int sz, vector<string> &strs, int m, int n, vector<vector<vector<int>>> &dp)
    {
        if (i == sz)
            return 0;
        if (dp[i][m][n] != -1)
            return dp[i][m][n];
        int one = 0, zero = 0, pick = 0;
        for (char c : strs[i])
        {
            if (c == '1')
                one++;
            else
                zero++;
        }
        if (m >= zero && n >= one)
            pick = 1 + help(i + 1, sz, strs, m - zero, n - one, dp);
        int notPick = help(i + 1, sz, strs, m, n, dp);
        return dp[i][m][n] = max(pick, notPick);
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int sz = strs.size();
        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return help(0, sz, strs, m, n, dp);
    }
};