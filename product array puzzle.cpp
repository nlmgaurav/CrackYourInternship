//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        vector<long long int>res;
            long long int cnt0=0,prod=1;
       for(int i=0;i<n;i++){
           if(nums[i]==0){
               cnt0++;
           }
           else{
               prod*=nums[i];
           }
       }
       for(int i=0;i<n;i++){
           if(nums[i]!=0 and cnt0==0){
               res.push_back(prod/nums[i]);
           }
           else if(nums[i]==0 and cnt0==1){
               res.push_back(prod);
           }
           else{
               res.push_back(0);
           }
           
       }
       return res;
    }
};
