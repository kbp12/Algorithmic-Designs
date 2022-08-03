class Solution {
public:
    int n,m;
    vector<int>xd = {0,-1,-1,-1,0,1,1,1};
    vector<int>yd = {-1,-1,0,1,1,1,0,-1};
    bool isPoint(int i,int j){
        return i>=0 and j>=0 and i<n and j<m;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j){
        if(board[i][j]=='M' or board[i][j]=='B' or (board[i][j]>='1' and board[i][j]<='9')) return;
        int count = 0;
        for(int k=0;k<8;k++){
            int a = i+xd[k];
            int b = j+yd[k];
            if(isPoint(a,b)){
                if(board[a][b]=='M'){
                    count++;
                }
            }
        }
        if(count == 0){
            board[i][j] = 'B';
        }else{
            board[i][j] = '0'+count;
        }
        if(board[i][j]=='B'){
            for(int k=0;k<8;k++){
                int a = i+xd[k];
                int b = j+yd[k];
                if(isPoint(a,b)){
                    dfs(board,a,b);
                }
            }
        }
        return;
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]]=='M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        n = board.size();
        m = board[0].size();
        dfs(board,click[0],click[1]);
        return board;
    }
};