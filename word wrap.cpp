int solve(vector<int>&arr,int i,int rem,int k, vector<vector<int>>&dp){
        
        if(i==arr.size())return 0;
        
        if(dp[i][rem+1]!=-1)return dp[i][rem+1];
        
        int ans;
        if(rem-arr[i]<0){
            
            ans=(rem+1)*(rem+1)+solve(arr,i+1,k-arr[i]-1,k,dp);
        }
        else{
            
            int a=(rem+1)*(rem+1)+solve(arr,i+1,k-arr[i]-1,k,dp);
            int b=solve(arr,i+1,rem-arr[i]-1,k,dp);
            ans =min(a,b);
        }
        return dp[i][rem+1]=ans ;
        
    }
    int solveWordWrap(vector<int>nums, int k) 
    { int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+2,-1));
        return solve(nums,0,k,k,dp);
    } 