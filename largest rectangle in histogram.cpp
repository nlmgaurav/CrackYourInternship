class Solution {
public:
vector<int> ls(vector<int>&heights)
{
    int n=heights.size();
    stack<int>st;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
        int x=!st.empty()?st.top():-1;
        ans.push_back(x);
        st.push(i);

    }
    return ans;
}
vector<int> rs(vector<int>&heights)
{
    int n=heights.size();
    stack<int>stk;
    vector<int>ans;
    for(int i=n-1;i>=0;i--)
    {
        while(!stk.empty() && heights[stk.top()]>=heights[i])stk.pop();
        int x=!stk.empty()?stk.top():n;
        ans.push_back(x);
        stk.push(i);

    }
    reverse(ans.begin(),ans.end());
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        vector<int>l=ls(heights);
        vector<int>r=rs(heights);
        for(int i=0;i<heights.size();i++){
            ans=max(ans,heights[i]*(r[i]-l[i]-1));
        }
        return ans;
    }
};