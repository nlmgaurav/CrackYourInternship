class Solution {
public:
#define ll long long
    int maxProduct(vector<int>& nums) {
         double ans=INT_MIN;
        double cprod=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
	        cprod=cprod*nums[i];
	        ans=max(ans,cprod);
	        if(cprod==0){
	            cprod=1;
	        }
	    }
        cprod=1;
        for(int i=n-1;i>=0;i--){
	        cprod=cprod*nums[i];
	        ans=max(ans,cprod);
	        if(cprod==0){
	            cprod=1;
	        }
	    }
        return ans;
    }
};