class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    for(int k=0;k<9;k++){
                        if(k!=i && board[k][j]==board[i][j]) return false;
                        if(k!=j && board[i][k]==board[i][j]) return false;
                    }
                    int a=i-i%3,b=j-j%3;
                    for(int p=0;p<3;p++){
                        for(int q=0;q<3;q++){
                            if(a+p!=i && b+q!=j && board[a+p][b+q]==board[i][j])return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};