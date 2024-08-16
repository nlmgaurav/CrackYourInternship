  int longestCommonSubstr(string S1, string S2) {
        // your code here
            int ans=0;
            int n=S1.size(),m=S2.size();
       int dp[n+1][m+1];
       
       //base case==intlization
       for(int i=0;i<n+1;i++)
       {
           for(int j=0;j<m+1;j++)
           {
               if(i==0 || j==0)dp[i][j]=0; // s1="abcd" s2="" or s1="" s2="abc" in both case w
               //we have to return 0 so we have marked as 0
               else if(S1[i-1]==S2[j-1]){
                   dp[i][j]=1+dp[i-1][j-1]; //if char are matching
                   ans=max(ans,dp[i][j]);
               }else{
                   dp[i][j]=0;// char are not matching
               }
           }
       }
       return ans;
    }