// User function Template for C++

class Solution
{
public:
    bool targetSum(int n, int arr[], int target)
    {
        int dp[n + 1][target + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < target + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = false;
                else if (j == 0)
                    dp[i][j] = true;
                else if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][target];
    }
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        if (sum % 2 != 0)
            return 0;
        return targetSum(n, arr, sum / 2);
    }
};