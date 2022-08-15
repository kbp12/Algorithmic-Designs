class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>left(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]=='E') left[i][0] = 1;
            for(int j=1;j<m;j++){
                if(grid[i][j]=='E') left[i][j] = 1 + left[i][j-1];
                else if(grid[i][j]=='W') left[i][j] = 0;
                else left[i][j] = left[i][j-1];
            }
        }
        vector<vector<int>>right(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(grid[i][m-1]=='E') right[i][m-1] = 1;
            for(int j=m-2;j>=0;j--){
                if(grid[i][j]=='E') right[i][j] = 1 + right[i][j+1];
                else if(grid[i][j]=='W') right[i][j] = 0;
                else right[i][j] = right[i][j+1];
            }
        }
        vector<vector<int>>top(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(grid[0][j]=='E') top[0][j] = 1;
            for(int i=1;i<n;i++){
                if(grid[i][j]=='E') top[i][j] = 1 + top[i-1][j];
                else if(grid[i][j]=='W') top[i][j] = 0;
                else top[i][j] = top[i-1][j];
            }
        }
        vector<vector<int>>bot(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(grid[n-1][j]=='E') bot[n-1][j] = 1;
            for(int i=n-2;i>=0;i--){
                if(grid[i][j]=='E') bot[i][j] = 1 + bot[i+1][j];
                else if(grid[i][j]=='W') bot[i][j] = 0;
                else bot[i][j] = bot[i+1][j];
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0'){
                    ans = max(ans,left[i][j]+right[i][j]+top[i][j]+bot[i][j]);
                }
            }
        }
        return ans;
    }
};