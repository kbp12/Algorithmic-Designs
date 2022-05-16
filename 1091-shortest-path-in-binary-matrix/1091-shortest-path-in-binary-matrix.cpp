class Solution {
public:
    bool check(int i,int j, int n){
        return i>=0 && j>=0 && i<=n && j<=n;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size()-1;
        if(grid[0][0]||grid[n][n]) return -1;
        vector<int>x = {-1,-1,-1,0,1,1,1,0};
        vector<int>y = {-1,0,1,1,1,0,-1,-1};
        queue<pair<int,int>>q;
        q.push(make_pair(0,0));
        grid[0][0]=1;
        while(!q.empty() && !grid[n][n]){
            pair<int,int>p = q.front(); q.pop();
            int a = p.first,b = p.second;
            for(int k=0;k<8;k++){
                int i = a+x[k];
                int j = b+y[k];
                if(check(i,j,n) && grid[i][j]==0){
                    q.push({i,j});
                    grid[i][j] = grid[a][b]+1;
                }
            }
        }
        if(grid[n][n]) return grid[n][n];
        return -1;
    }
};