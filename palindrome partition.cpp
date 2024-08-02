// User function Template for C++

class Solution
{
public:
    bool palindrome(string &s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    void help(int idx, string s, vector<string> &cur, vector<vector<string>> &ans)
    {
        if (idx >= s.size())
        {
            ans.push_back(cur);
            return;
        }
        string temp = "";
        for (int j = idx; j < s.size(); j++)
        {
            temp += s[j];
            if (palindrome(temp))
            {
                cur.push_back(temp);
                help(j + 1, s, cur, ans);
                cur.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> allPalindromicPerms(string s)
    {
        // code here
        vector<vector<string>> ans;
        int n = s.size();
        vector<string> cur;
        help(0, s, cur, ans);
        return ans;
    }
};