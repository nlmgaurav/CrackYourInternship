

  /*  firstly each 1's  k connected component ko ek unique id se change
  also maxrea of each island store krlo   mp[id]=area

  then each zero k adjacent mei find krenege ki area kitna hai  bss khtm

  one example: 
   1 0 1 -> 2 0 3
   0 1 1 -> 0 3 3
   1 0 1 -> 4 0 3

   Now, we traverse each 0 in the grid and find its adjacent group and add up their areas.
For the 0 at (0,1), we get area=m[2]+m[3]+1=1+4+1=6
For the 0 at (1,0), we get area=m[2]+m[3]+m[4]+1=1+4+1+1=7
We add 1 to account for the converted island.
tc=o(n^2)   sc=o(n^2)



Algorithm ->
1) pick a color, color the group of 1's and simultaneously calculate the are of 
   those 1's and store the pair (color, area)
2) traverse the grid again and find the zero, if it is a zero than add the area of
   colors on its 4 directions (NOTE: directions should be valid and we should not 
   add the redundant color).

   */
   
   
class Solution {
public:
    bool isValid(int i, int j, int n){
        if(i < 0 || j < 0 || i >= n || j >=n) return false;
        return true;
    }
    int dfs(vector<vector<int>> &grid, int i, int j, int color){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || grid[i][j] != 1)
            return 0;
        
        grid[i][j] = color;
        return 1 + dfs(grid, i + 1, j, color) + dfs(grid, i, j + 1, color) + dfs(grid, i - 1, j, color) + dfs(grid, i, j - 1, color);
        
    }
    int largestIsland(vector<vector<int>>& grid) {
          int n = grid.size();
          vector<int> colors (n * n + 2, 0);
          int color = 2;
          for(int i=0; i<n; i++){
              for(int j=0; j<n; j++){
                  if(grid[i][j] == 1){
                      int area = dfs(grid, i, j, color);
                      colors[color] = area;
                      color++;
                  }
              }
          }
        
         int area = 0;
         
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0)
                { set<int> col;
                if(isValid(i+1, j, n)) col.insert(grid[i+1][j]);
                if(isValid(i, j+1, n)) col.insert(grid[i][j+1]);
                if(isValid(i, j-1, n)) col.insert(grid[i][j-1]);
                if(isValid(i-1, j, n)) col.insert(grid[i-1][j]);
                int cur_area = 1;
                for(auto it : col) cur_area += (colors[(it)]);
                area = max(area, cur_area);
                }
            }
        }
          return area == 0 ? n * n : area;
    }
};




     