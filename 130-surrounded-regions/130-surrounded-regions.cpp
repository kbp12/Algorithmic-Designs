class Solution {
public:
    void bfs(int i,int j,int n,int m, vector<vector<char>>& b){
        if(i<0||i>=n||j<0||j>=m||b[i][j]!='O') return;
        b[i][j]='k';
        bfs(i+1,j,n,m,b);
        bfs(i-1,j,n,m,b);
        bfs(i,j+1,n,m,b);
        bfs(i,j-1,n,m,b);
        return;
    }
    
    void solve(vector<vector<char>>& b) {
        int n = b.size(), m = b[0].size();
        for(int i=0;i<n;i++){
            if(b[i][0]=='O'){
                bfs(i,0,n,m,b);
            }
            if(b[i][m-1]=='O'){
                bfs(i,m-1,n,m,b);
            }
        }
        for(int i=0;i<m;i++){
            if(b[0][i]=='O'){
                bfs(0,i,n,m,b);
            }
            if(b[n-1][i]=='O'){
                bfs(n-1,i,n,m,b);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]=='O') b[i][j]='X';
                else if(b[i][j]=='k') b[i][j] = 'O';
            }
        }
        return;
    }
};