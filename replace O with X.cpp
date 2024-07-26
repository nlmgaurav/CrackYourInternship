// User function Template for C++

class Solution{
public:
  void help(int i,int j,int n,int m,vector<vector<char>>&mat)
{
    if(i<0 || j<0 || i>=n || j>=m || mat[i][j]!='O')return ;
    

    mat[i][j]='*';
    help(i+1,j,n,m,mat);
        help(i-1,j,n,m,mat);
            help(i,j+1,n,m,mat);
                help(i,j-1,n,m,mat);
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        
        
     if(n==0)return mat;
     for(int i=0;i<n;i++)
     {
         if(mat[i][0]=='O')help(i,0,n,m,mat);
         if(mat[i][m-1]=='O')help(i,m-1,n,m,mat);
     }
   for(int j=0;j<m;j++)
   {
       if(mat[0][j]=='O')help(0,j,n,m,mat);
       if(mat[n-1][j]=='O')help(n-1,j,n,m,mat);
   }
   
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(mat[i][j]=='O')mat[i][j]='X';
           if(mat[i][j]=='*')mat[i][j]='O';
       }
   }
   
     return mat;
     
     
     
    }
};