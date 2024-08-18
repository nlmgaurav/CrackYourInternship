class Solution {
public:
    
    // declare a dp
    
    int dp[105][105][105];
    
    int dfs(vector<int>& arr, int left, int right, int streak)
    {
        // base case
        
        if(left > right)
            return 0;
        
        // if already is calculated
        
        if(dp[left][right][streak] != -1)
            return dp[left][right][streak];
        
        int maxi = 0;
        
        // break the streak at curr position
        
        maxi =  (streak + 1) * (streak + 1) + dfs(arr, left + 1, right, 0);
        
        // remove all the subarrays with different colors
        
        for(int i = left + 1; i <= right; i++)
        {
            if(arr[i] == arr[left])
            {
                maxi = max({maxi, dfs(arr, left + 1, i - 1, 0) + dfs(arr, i, right, streak + 1)});
            }
        }
        
        // store the maxi and then return
        
        return dp[left][right][streak] = maxi;
    }
    
    int removeBoxes(vector<int>& boxes) {
        
        int n = boxes.size();
        
        memset(dp, -1, sizeof(dp));
        
        return dfs(boxes, 0, n - 1, 0);
    }
};