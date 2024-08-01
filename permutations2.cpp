class Solution {
public:
    
    void helper(vector<int>nums,vector<vector<int>>&ans,int idx)
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            if(nums[i]!=nums[idx])
            {
                swap(nums[i],nums[idx]);
                helper(nums,ans,idx+1);
            }
           else if(i==idx)helper(nums,ans,idx+1);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        helper(nums,ans,0);
        return ans;
    }
};