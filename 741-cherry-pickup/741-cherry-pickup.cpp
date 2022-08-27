class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        //considering two persons moving simultaneously
        int dp[n+1][n+1][n+1][n+1];
        memset(dp,-1,sizeof(dp));
        int y;
        dp[1][1][1][1] = grid[0][0];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int x=1;x<=n;x++){
                    y = i+j-x;
                    if(y<1 or y>n or grid[i-1][j-1]==-1 or grid[x-1][y-1]==-1) continue;
                    int val = -1;
                    val = max({dp[i-1][j][x-1][y],dp[i-1][j][x][y-1],dp[i][j-1][x-1][y],dp[i][j-1][x][y-1]});
                    if(val==-1) continue;
                    if(i==x){
                        val+=grid[i-1][j-1];
                    }else{
                        val+=grid[i-1][j-1]+grid[x-1][y-1];
                    }
                    dp[i][j][x][y] = val;
                }
            }
        }
        return dp[n][n][n][n]==-1?0:dp[n][n][n][n];
    }
};