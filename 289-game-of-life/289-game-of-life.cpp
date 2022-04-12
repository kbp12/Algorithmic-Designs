class Solution {
public:
    int find_it(int i, int j, int m, int n, vector<vector<int>>& board){
        int count =0;
        if(i-1>=0 && j-1>=0){if(board[i-1][j-1]==1 || board[i-1][j-1]==-2) count++;}
        if(i-1>=0){if(board[i-1][j]==1 || board[i-1][j]==-2) count++;}
        if(i-1>=0 && j+1<n){if(board[i-1][j+1]==1 || board[i-1][j+1]==-2) count++;}
        if(j-1>=0){if(board[i][j-1]==1 || board[i][j-1]==-2) count++;}
        if(j+1<n){if(board[i][j+1]==1 || board[i][j+1]==-2) count++;}
        if(i+1<m && j-1>=0){if(board[i+1][j-1]==1 || board[i+1][j-1]==-2) count++;}
        if(i+1<m){if(board[i+1][j]==1 || board[i+1][j]==-2) count++;}
        if(i+1<m && j+1<n){if(board[i+1][j+1]==1 || board[i+1][j+1]==-2) count++;}
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //live defines the number of live neighbours of cell(i,j)
                int live = find_it(i,j,m,n,board);
                if(board[i][j]==0){
                    if(live==3) board[i][j] = -1;
                }else{
                    if(live<2) board[i][j] = -2;
                    else if(live>3) board[i][j] = -2;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==-2) board[i][j] = 0;
                else if(board[i][j]==-1) board[i][j] = 1;
            }
        }
        return;
    }
};