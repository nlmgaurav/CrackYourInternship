class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        int res;
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0' && s[i]<='9'){
                st.push(s[i]-'0');
            }else{
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(s[i]=='+'){
                    res=a+b;
                }
                 if(s[i]=='-'){
                    res=b-a;
                }
                 if(s[i]=='*'){
                    res=a*b;
                }
                 if(s[i]=='/'){
                    res=b/a;
                }
                st.push(res);
            }
        }
        return st.top();
    }
};