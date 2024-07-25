class Solution {
public:
    string reverseWords(string s) {
     stack<string>st;
      string temp="";
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(temp.size()>0){
                    st.push(temp);
                    temp="";
                }
                
            }else
                temp=temp+s[i];
        }
        ans=ans+temp;
        while(!st.empty()){
            ans=ans+" "+st.top();
            st.pop();
        }
        if(ans.length()!=0 && ans[0]==' ')
            ans=ans.substr(1);
        return ans;
    }
};