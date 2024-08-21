class Solution {
public:
    int countPalindromicSubsequences(string str) {
        int n = str.size() ; 
        long long mod = 1000000007 ; 
        vector<int>next(n) , prev(n) ; 
        map<char,int>m ; 
        for(int i = 0 ; i<n ; i++)
        {
            char ch = str[i] ; 
            if(m[ch])
            {
                prev[i] = m[ch] - 1 ; 
                m[ch] = i + 1 ; 
            }
            else
            {
                m[ch] = i+1 ; 
                prev[i] = -1 ; 
            }
        }
        m.clear() ; 
        for(int i = n-1 ; i>=0 ; i--)
        {
            char ch = str[i] ; 
            if(m[ch])
            {
                next[i] = m[ch] - 1 ; 
                m[ch] = i + 1 ; 
            }
            else
            {
                m[ch] = i + 1 ; 
                next[i] = -1 ; 
            }
        }

        vector<vector<long long>>dp(n , vector<long long>(n , 0)) ; 
        int i = 0 ; 
        int j = 0 ; 
        int lastcol = 0 ;
        while(1)
        {
            while(i < n && j < n)
            {
                int gap = j - i ; 
                if(gap == 0) dp[i][j] = 1 % mod ; 
                else if(gap == 1) dp[i][j] = 2 % mod ; 
                else 
                {
                    if(str[i] != str[j]) dp[i][j] = (dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]) % mod ; 
                    else
                    {
                        if(next[i] == j && prev[j] == i) dp[i][j] = (2 * dp[i+1][j-1] + 2) % mod ;
                        else if(next[i] == prev[j]) dp[i][j] = (2 * dp[i+1][j-1] + 1) % mod ; 
                        else dp[i][j] = (2 * dp[i+1][j-1] - dp[next[i] + 1][prev[j] - 1]) % mod ;   
                    }
                }
                i++ ; 
                j++ ; 
            }
            if(lastcol == n-1) break ; 
            i = 0 ; 
            j = lastcol + 1 ; 
            lastcol = j ; 
        }
        if(dp[0][n-1] < 0) dp[0][n-1] += mod ; 
        return dp[0][n-1] ;
    }
};