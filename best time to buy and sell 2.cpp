/*class Solution {
public:
int f(int i,int buy,vector<int>&prices)
{
   if(i==prices.size())return 0;
    int profit=0;
    if(buy)
    {
        int take=-prices[i]+f(i+1,0,prices);
        int notTake=0+f(i+1,1,prices);
        profit=max(take,notTake);
    }else
    {
        int sell=prices[i]+f(i+1,1,prices);
        int notSelling=0+f(i+1,0,prices);
        profit=max(sell,notSelling);
    }
    return profit;
}
    int maxProfit(vector<int>& prices) {
        return f(0,1,prices);  // idx,buy,prices
    }
};*/

class Solution {
public:
int f(int i,int buy,vector<int>&prices,vector<vector<int>>&dp)
{
   if(i==prices.size())return 0;
    int profit=0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    if(buy)
    {
        int take=-prices[i]+f(i+1,0,prices,dp);
        int notTake=0+f(i+1,1,prices,dp);
        profit=max(take,notTake);
    }else
    {
        int sell=prices[i]+f(i+1,1,prices,dp);
        int notSelling=0+f(i+1,0,prices,dp);
        profit=max(sell,notSelling);
    }
    return  dp[i][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);  // idx,buy,prices
    }
};