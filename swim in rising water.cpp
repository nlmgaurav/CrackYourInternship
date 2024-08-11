class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>vis(n,vector<int>(n,0));

        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};

        pq.push({grid[0][0],{0,0}});  // cost, i,j


        vis[0][0]=1;
        while(!pq.empty())
        {
            auto cur=pq.top();
            pq.pop();
            int cost=cur.first;
            int x=cur.second.first;
            int y=cur.second.second;
            if(x==n-1 && y==n-1)return cost;
            
            
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n && vis[nx][ny]!=1 ){
                   vis[nx][ny]=1;
                   if(grid[nx][ny]>cost)pq.push({grid[nx][ny],{nx,ny}});
                   else pq.push({cost,{nx,ny}});
                }
            }
        }
        return 0;
    }
};