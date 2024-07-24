class Solution {
public:
    void solve(vector <int> &nums,int idx,vector <int> &res, vector <vector<int>> &ans)
    {
        ans.push_back(res);
        for(int i=idx;i<nums.size();i++){
            if(i!=idx && nums[i]==nums[i-1])
                continue;
            res.push_back(nums[i]);
            solve(nums,i+1,res,ans);
            res.pop_back();
        } 
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector <vector <int> >ans;
        vector <int> res;
        sort(nums.begin(),nums.end());
        solve(nums,0,res,ans);
        return ans;
    }
};