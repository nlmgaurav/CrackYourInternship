class Solution {
public:
   int solve(int i, map<int,int>&m, vector<int>&nums, vector<int>&ans){
    if(i>=nums.size()) return 0;
    if(ans[i]!=-1) return ans[i];
    int take=nums[i]*m[nums[i]]+solve(upper_bound(nums.begin(),nums.end(),nums[i]+1)-nums.begin(),m,nums,ans);
    int nottake=solve(i+1,m,nums,ans);
    return ans[i]=max(nottake,take);
}
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>m;
        sort(nums.begin(), nums.end());
        for(auto it: nums){
            m[it]++;
        }
        vector<int>ans(nums.size()+1,-1);
        return solve(0,m,nums,ans);
    }
};