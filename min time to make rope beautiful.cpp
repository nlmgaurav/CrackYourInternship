class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
           int ans=0;
        int n=colors.size();
        for(int i=0;i<n;i++){
            if(i+1<n && colors[i]==colors[i+1]){
                if(neededTime[i]<neededTime[i+1]){
                        ans+=neededTime[i];
                }else{
                    ans+=neededTime[i+1];
                    neededTime[i+1]=neededTime[i];
                }
            }
        }
        return ans;
    }
};