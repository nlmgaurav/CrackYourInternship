class Solution {
public:

void dfs(int src,unordered_map<int,vector<int>>&mp,set<int>&visited,vector<int>&ans)
{
    if(visited.find(src)!=visited.end())return;
    ans.push_back(src);
    visited.insert(src);
    for(auto x:mp[src])dfs(x,mp,visited,ans);

    
}
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>mp;
        for(auto it:adjacentPairs){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        int head=0;
        for(auto it:mp){
            if(it.second.size()==1){
                head=it.first;
                break;
            }
        }
        vector<int>ans;
        set<int>visited;
        dfs(head,mp,visited,ans);
        return ans;
    }
};