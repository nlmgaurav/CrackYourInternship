class Solution {
public:
    bool safe(int x,int y,int R,int C){
        return(x>=0 && x<R && y>=0 && y<C);
    }
    void gameOfLife(vector<vector<int>>& board) {
        int R=board.size();
        int C=board[0].size();
        int dx[]={1,1,0,-1,-1,-1,0,1};
        int dy[]={0,1,1,1,0,-1,-1,-1};
        vector<vector<int>>cpy=board;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cpy[i][j]=board[i][j];
            }
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                int liveCount=0;
                for(int k=0;k<8;k++){
                    if(safe(i+dx[k],j+dy[k],R,C) && cpy[i+dx[k]][j+dy[k]]==1)
                        liveCount++;
                    
                }
                if(cpy[i][j]==0 && liveCount==3)board[i][j]=1;
                if(board[i][j]==1 && liveCount<2 || liveCount>3)board[i][j]=0;
            }
        }
    }
};