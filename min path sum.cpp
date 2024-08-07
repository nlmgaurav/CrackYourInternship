class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        vector<vector<int>>dp(rows,vector<int>(cols,0));
        // for 0'th row lets suppose (0,2) we have only one option to reach this cell
        // which is from (0,1) ---> (0,2)  
        // so for 0;th row dp value would be simply current cell value+ previous cell value
        // same for 0;th col
        // for all other cells  dp[i][j]==grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
        dp[0][0]=grid[0][0];
        // 0"th row"
        for(int i=1;i<cols;i++)dp[0][i]=dp[0][i-1]+grid[0][i];
        // 0'Th col
        for(int i=1;i<rows;i++)dp[i][0]=dp[i-1][0]+grid[i][0];
        // for others cells
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
        }
        return dp[rows-1][cols-1];
    }
};