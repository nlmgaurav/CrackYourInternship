//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<string_list.size();i++){
            string s=string_list[i];
            sort(s.begin(),s.end());
            mp[s].push_back(string_list[i]);
            
        }
        vector<vector<string>>ans(mp.size());
        int idx=0;
        for(auto it:mp){
            auto v=it.second;
            for(int i=0;i<v.size();i++){
                ans[idx].push_back(v[i]);
            }
            idx++;
        }
       return ans; 
        
    }
};