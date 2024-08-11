class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        // first window
        for(int i=0;i<k;i++)
        {
            while(!dq.empty() && dq.back()<nums[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(nums[i]);
            
        }
        ans.push_back(dq.front());
        for(int i=k;i<nums.size();i++)
        {
           if(dq.front()==nums[i-k])dq.pop_front();
            while(!dq.empty() && dq.back()<nums[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(nums[i]);
            ans.push_back(dq.front());
        }
        return ans;
    }
};