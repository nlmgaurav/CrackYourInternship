class Solution {
public:

/* dp with bitmasking   
mask ka use krre ki whether cur city visited hai ya nhi

*/
 int rec(int pos, vector<vector<int>>&cost, int mask, int n,vector<vector<int>>&dp)
 
  {
       
        if(mask== ((1<<n)-1))  // this means we have covered alll cities 1<<n)-1  n times 1111
        {
              return cost[pos][0];   // curPosition se 0 tk ka cost as mentioned in question
        }
        
        if(dp[pos][mask]!=-1)
        return dp[pos][mask];
        
        int res=INT_MAX;
        
        for(int city=0;city<n;city++)
        {
             if( (mask&(1<<city))==0)  // this meanse cur city visited nhi hai
             {
                  // this is subproblem curpos se city tk ka cost +  aage ka problem
                  
                    int temp= cost[pos][city]+ rec(city,cost,mask|(1<<city),n,dp);
                    
                    res=min(res,temp);
             }
        }
        
        return dp[pos][mask]=res;
  }
int total_cost(vector<vector<int>>cost){
    // Code here
    int n=cost.size();
    vector<vector<int>>dp(n+5,vector<int>((1<<n),-1));
       int mask=1;
       return rec(0,cost,mask,n,dp);
}
};