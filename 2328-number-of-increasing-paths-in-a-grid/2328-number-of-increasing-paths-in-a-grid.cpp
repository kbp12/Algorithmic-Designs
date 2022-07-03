class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>>direction = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int dfs(vector<vector<int>>&grid, int i, int j, vector<vector<int>>& dp){
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int ans = 0;
        for(int k=0;k<4;k++){
            int r = i+direction[k][0];
            int c = j+direction[k][1];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]>grid[i][j]){
                ans = (ans+dfs(grid,r,c,dp))%mod;
            }
        }
        ans++;
        dp[i][j] = (ans)%mod;
        return ans;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j = 0 ; j < m ; j++ ){
                if(dp[i][j] == INT_MAX) dfs(grid,i,j,dp);
            }
        }
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m; j++){
                ans= ((ans%mod)+(dp[i][j]%mod))%mod;
            }
        }
        return ans;
    }
};