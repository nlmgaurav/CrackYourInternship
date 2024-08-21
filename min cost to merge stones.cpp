class Solution {
public:
    
    // declare a dp
    
    int dp[35][35];
    
    int helper(vector<int>& arr, int start, int end, vector<int>& prefix, int k)
    {
        // if no. of elements is less than k
        
        if(end - start <= k - 2)
        {
            return 0;
        }
        
        // if already calculated
        
        if(dp[start][end] != -1)
        {
            return dp[start][end];
        }
        
        int mini = INT_MAX;
        
        // partition the array at j
        
        for(int j = start; j < end; j += k - 1)
        {
            int left = helper(arr, start, j, prefix, k);
            
            int right = helper(arr, j + 1, end, prefix, k);
            
            mini = min({mini, left + right});
        }
        
        // add the cost of merging two part
        
        if((end - start) % (k - 1) == 0)
        {
            int sum = 0;
            
            sum += prefix[end];
            
            if(start > 0)
            {
                sum -= prefix[start - 1];
            }
                
            mini += sum;
        }
        
        // store the res and return
     
        return dp[start][end] = mini;
    }
    
    int mergeStones(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        // if it is not possible
        
        if((n - 1) % (k - 1))
        {
            return -1;
        }
        
        // find the prefix sum
        
        vector<int> prefix(n, 0);
        
        prefix[0] = arr[0];
        
        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        
        // initialize dp with -1
        
        memset(dp, -1, sizeof(dp));
        
        return helper(arr, 0, n - 1, prefix, k);
    }
};