class Solution {
public:
    int mis(string s1,string s2,int n,int m){
        int size=min(n,m);
        int length=0;
        for(int i=0;i<size;i++){
            if(s1[i]==s2[i])length++;
            else
                break;
        }
        return length;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0)return "";
       sort(strs.begin(),strs.end());
        string ans="";
        string s1=strs[0],s2=strs[n-1];
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i]){
                ans+=s1[i];
            }else{
                break;
            }
        }
        return ans;
       /* string ans=strs[0];
        int length=ans.size();
        for(int i=1;i<n;length>0;i++){
            length=mis(ans,strs[i],length,ans[i].length);
        }
        return s.substr(0,length);*/
    }
};