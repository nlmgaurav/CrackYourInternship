class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i:nums){
            i=abs(i);
            if(nums[i-1]>0){
                nums[i-1]=nums[i-1]*-1;
            }else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};