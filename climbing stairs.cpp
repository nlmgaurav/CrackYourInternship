class Solution {
public:
    int climbStairs(int n) {
       if(n<=1)return n;
       int prev=1,prev1=1;
       for(int i=2;i<=n;i++)
       {
           int cur=prev+prev1;
           prev=prev1;
           prev1=cur;
       }
       return prev1;
    }
};