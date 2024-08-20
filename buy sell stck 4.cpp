class Solution {
public:
int help(int i,int trans,int k,int n,vector<int>&prices,vector<vector<int>>&dp)
{
    if(i==n || trans==2*k)return 0;
    if(dp[i][trans]!=-1)return dp[i][trans];
    if(trans%2==0){
    return dp[i][trans]= max(-prices[i]+help(i+1,trans+1,k,n,prices,dp),help(i+1,trans,k,n,prices,dp));
    }
    return dp[i][trans]=max(prices[i]+help(i+1,trans+1,k,n,prices,dp),help(i+1,trans,k,n,prices,dp));
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2*k+1,-1));
        return help(0,0,k,n,prices,dp);
    }
};