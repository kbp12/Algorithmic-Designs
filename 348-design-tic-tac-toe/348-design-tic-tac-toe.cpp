class TicTacToe {
public:
    int n;
    vector<vector<int>>v;
    TicTacToe(int N) {
        n = N;
        v = vector<vector<int>>(n,vector<int>(n,0));
        return;
    }
    
    vector<int>dx = {-1,1,0,0,-1,1,-1,1};
    vector<int>dy = {0,0,-1,1,-1,1,1,-1};
    
    int move(int r, int c, int p){
        v[r][c] = p;
        vector<int>idx = {0,2};
        if(r==c and r+c==n-1){
            idx.push_back(4);
            idx.push_back(6);
        }else if(r==c){
            idx.push_back(4);
        }else if(r+c==n-1){
            idx.push_back(6);
        }
        for(int t=0;t<idx.size();t++){
            int k = idx[t];
            int x = k, y = k+1;
            int i = r, j = c;
            bool yes = true;
            while(i>=0 and j>=0 and i<n and j<n){
                if(v[i][j]!=p){
                    yes = false;
                    break;
                }
                i+=dx[x];
                j+=dy[x];
            }
            i = r, j = c;
            while(i>=0 and j>=0 and i<n and j<n){
                if(v[i][j]!=p){
                    yes = false;
                    break;
                }
                i+=dx[y];
                j+=dy[y];
            }
            if(yes) return p;
        }
         return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */