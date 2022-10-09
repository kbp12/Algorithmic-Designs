class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size(), mod = 1e9+7;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k,0)));
        dp[0][1][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int rem = grid[i-1][j-1]%k;
                for(int kk=0;kk<k;kk++){
                    int idx = (rem+kk)%k;
                    dp[i][j][idx] = (dp[i-1][j][kk] + dp[i][j-1][kk])%mod;
                }
            }
        }
        return dp[n][m][0];
    }
};