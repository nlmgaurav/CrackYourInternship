 int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int total=0,cnt=0,days=0;
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])total++;
                if(grid[i][j]==2)q.push({i,j});
            }
        }
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        while(!q.empty())
        {
            int k=q.size();
            cnt+=k;
            while(k--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx<0 || ny<0 || nx>=grid.size() || ny>=grid[0].size() || grid[nx][ny]!=1)continue;
                    q.push({nx,ny});
                    grid[nx][ny]=2;
                
                }
            }
            if(!q.empty())days++;
        }
        return total==cnt?days:-1;
        
    }