class Solution {
public:
    int minMoves2(vector<int>& nums) {
      sort(nums.begin(),nums.end());
        int n=nums.size(),ans=0;
        int median=nums[n/2];
        for(int i=0;i<n;i++)ans+=abs(nums[i]-median);
        return ans;
    }
};