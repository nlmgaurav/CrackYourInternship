class Solution {
public:
    void help(int idx,int                     target,vector<int>&arr,vector<vector<int>>&ans,vector<int>ds)
    {
        // base case
        if(target==0){
            ans.push_back(ds);
            return;   
        }
        
        for(int i=idx;i<arr.size();i++)
        {
            if(i>idx && arr[i]==arr[i-1])continue;  //if we ahve atken 
            //1 in 1 call then dont take in next call
            if(arr[i]>target)break;
            ds.push_back(arr[i]);
            help(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        help(0,target,candidates,ans,ds);
        return ans;
    }
};