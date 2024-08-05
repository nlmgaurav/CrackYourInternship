class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> ans;
        int len = 1;
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > ans.back())
            {
                len++;
                ans.push_back(nums[i]);
            }
            else
            {
                int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[idx] = nums[i];
            }
        }
        // for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        return len;
    }
};