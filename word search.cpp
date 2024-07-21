class Solution {
public:
    
    bool dfs(int i,int j,vector<vector<char>>& board, string word,int n)
    {
        if(n==word.size())return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[n])return false;
        char ch=board[i][j];
        board[i][j]='*';
        bool status=dfs(i+1,j,board,word,n+1) || dfs(i-1,j,board,word,n+1) || dfs(i,j+1,board,word,n+1) || dfs(i,j-1,board,word,n+1);
        board[i][j]=ch;
        return status;
        
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(i,j,board,word,0))return true;
                }
            }
        }
        
        
        return false;
        
    }
};