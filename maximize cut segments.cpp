int help(int n,int x,int y,int z,vector<int>&dp)
    {
        if(n<0)return -1;
        if(n==0)return 0;
        if(dp[n]!=INT_MIN)return dp[n];
        int op1=help(n-x,x,y,z,dp),op2=help(n-y,x,y,z,dp),op3=help(n-z,x,y,z,dp);
        if(op1==-1 && op2==-1 && op3==-1)return dp[n]=-1;
        return dp[n]=max({op1,op2,op3})+1;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1,INT_MIN);
        int ans=help(n,x,y,z,dp);
        if(ans==-1)return 0;
        return ans;
    }
    // simple dp three choices