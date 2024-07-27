class Solution {
public:

    void dfs(int x,int y,vector<vector<char>>&grid){
            int dx[]={0,0,-1,1};
            int dy[]={-1,1,0,0};
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]=='0')return;
        grid[x][y]='0';
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]=='1')
                dfs(nx,ny,grid);
        }
            
        }
            
    
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};