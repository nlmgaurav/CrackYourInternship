 void dfs(int row,int col,vector<vector<int>> &m,int n,string op,vector<string>& ans){
       if(row<0 || col<0 || row>=n || col>=n || m[row][col]==0) return;
       
       if(row==n-1 && col==n-1){
          ans.push_back(op);return;
       }
       //do
       m[row][col]=0;
       //recur
       dfs(row+1,col,m,n,op+'D',ans);
       dfs(row-1,col,m,n,op+'U',ans);
       dfs(row,col+1,m,n,op+'R',ans);
       dfs(row,col-1,m,n,op+'L',ans);
       //backtrack
       m[row][col]=1;
   }
   vector<string> findPath(vector<vector<int>> &m, int n) {
       // Your code goes here
       if(m[0][0]==0 || m[n-1][n-1]==0) return {"-1"};
       vector<string> ans;
       string op="";
       dfs(0,0,m,n,op,ans);
       return ans;
   }