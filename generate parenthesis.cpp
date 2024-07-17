class Solution {
public:

void help(int o,int c,string cur,int n,vector<string>&ans)
{
    if(o==n && c==n)
    {
        ans.push_back(cur);
        return;
    }
    if(o<n)
        help(o+1,c,cur+"(",n,ans);
    
    if(c<o)help(o,c+1,cur+")",n,ans);
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;

      help(0,0,"",n,ans);
      return ans;
        
    }
};