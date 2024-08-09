class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        int n = s.length();

        stack<pair<char, int>> st;
        string ans = "";

        for (int i = 0; i < n; ++i)
        {
            if (st.empty())
            {
                st.push({s[i], 1});
            }
            else
            {

                if (st.top().first == s[i])
                {
                    int freq = st.top().second + 1;
                    st.pop();
                    st.push({s[i], freq});
                }
                else
                {
                    st.push({s[i], 1});
                }

                if (st.top().second == k)
                {
                    st.pop();
                }
            }
        }

        while (!st.empty())
        {
            int cnt = st.top().second;
            while (cnt--)
            {
                ans += st.top().first;
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};