bool isKPartitionPossible(int a[], int n, int k)
{
    sort(a, a + n);
    int totalSum = 0;
    if (k == 1)
        return true;
    if (k > n)
        return false;
    for (int i = 0; i < n; i++)
        totalSum += a[i];
    if (totalSum % k != 0)
        return false;
    else
    {
        int targetSum = totalSum / k;
        int *arr = new int[n];
        vector<bool> vis(n, false);
        int j = 0;
        while (k - 1 != j)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (arr[j] < targetSum && a[i] + arr[j] <= targetSum && vis[i] == false)
                {
                    arr[j] += a[i];
                    vis[i] = true;
                }
            }
            if (arr[j] != targetSum)
                return false;
            else
                j++;
        }
        return true;
