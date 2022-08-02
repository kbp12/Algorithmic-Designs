class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<char>>& board){
        if(i<0 or i>=m or j<0 or j>=n or board[i][j]=='.') return;
        board[i][j] = '.';
        dfs(i-1,j,m,n,board);
        dfs(i+1,j,m,n,board);
        dfs(i,j-1,m,n,board);
        dfs(i,j+1,m,n,board);
        return;
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    ans++;
                    dfs(i,j,m,n,board);
                }
            }
        }
        return ans;
    }
};