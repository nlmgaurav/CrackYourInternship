  
    int celebrity(vector<vector<int> >& mat, int n) 
    {
           stack<int>s;
           for(int i=0;i<n;i++)s.push(i);
           int count=0;
           while(count<n-1)
           {
              int first=s.top();
              s.pop();
              int second=s.top();
              s.pop();
              if(mat[first][second]==1){
                  s.push(second);
              }else{
                  s.push(first);
              }
              count++;
           }
        int candidate=s.top();
        s.pop();
        for(int i=0;i<n;i++){
            if(mat[candidate][i]==1 && candidate!=i)return -1;
            if(mat[i][candidate]==0 && candidate!=i)return -1;
        }
        return candidate;
           
    }