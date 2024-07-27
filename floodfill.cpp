class Solution {
public:
    //color=> newColor and oldColor the color (sr,sc)already having
    // we will only fill our new color if his neighbours  are same color
    
    void dfs(vector<vector<int>>& image, int row, int col, int color,int oldColor)
    {
    if(row<0 || row>=image.size() || col<0 || col>=image[0].size() || image[row][col]!=oldColor)return;
        image[row][col]=color;
        dfs(image,row-1,col,color,oldColor);
          dfs(image,row+1,col,color,oldColor);
          dfs(image,row,col-1,color,oldColor);
          dfs(image,row,col+1,color,oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(image[sr][sc]==newColor)return image;
        dfs(image,sr,sc,newColor,image[sr][sc]);
        return image;
        
    }
};