class Solution {
public:
    void helper(vector<vector<int>>&ans,int n,int k,int idx,vector<int>temp)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx;i<n;i++)
        {
            temp.push_back(i+1);
            helper(ans,n,k,i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>>ans;
        helper(ans,n,k,0,vector<int>());
        return ans;
        
        
    }
};