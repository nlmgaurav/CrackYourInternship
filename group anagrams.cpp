class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            string cur=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(cur);
        }
        for(auto it=mp.begin();it!=mp.end();it++)ans.push_back(it->second);
        return ans;
    }
};