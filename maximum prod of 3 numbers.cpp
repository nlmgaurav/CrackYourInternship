class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       /*
       O(N) + O(1)
       
       int mn1=10001,mn2=10001,mx1=-10001,mx2=-10001,mx3=-10001;
        for(auto num:nums){
            if(num>mx1){
                mx3=mx2;
                mx2=mx1;
                mx1=num;
            }else if(num>mx2){
                mx3=mx2;
                mx2=num;
            }else if(num>mx3)mx3=num;
            if(num<mn1){mn2=mn1;
            mn1=num;
         }else if(num<mn2){
                mn2=num;
            }
        }
        return max(mx1*mx2*mx3,mx1*mn1*mn2);
        */
        
        // O(NLOGN)
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return max(nums[n-1]*nums[n-2]*nums[n-3],max(nums[0]*nums[1]*nums[2],nums[0]*nums[1]*nums[n-1]));
    }
};