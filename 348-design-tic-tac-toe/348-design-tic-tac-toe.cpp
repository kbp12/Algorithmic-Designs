class TicTacToe {
public:
    vector<int>row, col;
    int dia, antidia, n;
    TicTacToe(int sz) {
        n = sz;
        dia = antidia = 0;
        row.resize(n,0);
        col.resize(n,0);
    }
    
    int move(int r, int c, int p) {
        if(p==1){
            row[r]++;
            col[c]++;
            if(r==c) dia++;
            if(r+c==n-1) antidia++;
            if(row[r]==n or col[c]==n or dia==n or antidia==n){ return p;}
        }else{
            row[r]--;
            col[c]--;
            if(r==c) dia--;
            if(r+c==n-1) antidia--;
            if(row[r]==-n or col[c]==-n or dia==-n or antidia==-n){ return p;}
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */