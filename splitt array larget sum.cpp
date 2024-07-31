class Solution {
public:

  bool valid(vector<int>&nums,int mid,int k)
  {
      int cnt=1;
      int curSum=0;
      for(int i=0;i<nums.size();i++)
      {
          if(curSum+nums[i]<=mid)curSum+=nums[i];
          else 
          {
             cnt++;
             curSum=nums[i];
          }
      }
      return cnt<=k;
  }

    int splitArray(vector<int>& nums, int k) {
        int low=0,high=0,ans=0;
        low=*max_element(nums.begin(),nums.end());
        for(int num:nums)high+=num;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(valid(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};