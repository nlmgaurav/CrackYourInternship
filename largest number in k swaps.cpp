

class Solution
{
public:
    // Function to find the largest number after k swaps.
    void help(string &s, int i, int k, string &ans)
    {
        ans = max(ans, s);
        if (k == 0 || i >= s.size())
            return;
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[j] > s[i])
            {
                swap(s[i], s[j]);
                help(s, i + 1, k - 1, ans);
                swap(s[i], s[j]);
            }
        }
        help(s, i + 1, k, ans);
    }
    string findMaximumNum(string str, int k)
    {
        // code here.
        string ans = str;
        help(str, 0, k, ans);
        return ans;
    }
};