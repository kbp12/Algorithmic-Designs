class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited, int i, int j, int n){
        if(i<0 or j<0 or i>=n or j>=n or grid[i][j]==0 or visited[i][j]) return 0;
        int sz = 1;
        visited[i][j] = true;
        sz+=dfs(grid,visited,i+1,j,n);
        sz+=dfs(grid,visited,i-1,j,n);
        sz+=dfs(grid,visited,i,j-1,n);
        sz+=dfs(grid,visited,i,j+1,n);
        return sz;
    }
    
    void dfs2(vector<vector<int>>& grid, vector<vector<pair<int,int>>>& dp, int i, int j, int n, int cnt, int grp){
        if(i<0 or j<0 or i>=n or j>=n or grid[i][j]==0 or dp[i][j].first!=0) return;
        dp[i][j].first = cnt;
        dp[i][j].second = grp;
        dfs2(grid,dp,i+1,j,n,cnt,grp);
        dfs2(grid,dp,i-1,j,n,cnt,grp);
        dfs2(grid,dp,i,j+1,n,cnt,grp);
        dfs2(grid,dp,i,j-1,n,cnt,grp);
        return;
    }
    
    int dfs3(vector<vector<pair<int,int>>>& dp, int i, int j, int n){
        unordered_set<int>s;
        int cnt = 1;
        if(i>0){
            cnt+=dp[i-1][j].first;
            s.insert(dp[i-1][j].second);
        }
        if(j>0 and s.find(dp[i][j-1].second) == s.end()){
            cnt+=dp[i][j-1].first;
            s.insert(dp[i][j-1].second);
        }
        if(i<n-1 and s.find(dp[i+1][j].second) == s.end()){
            cnt+=dp[i+1][j].first;
            s.insert(dp[i+1][j].second);
        }
        if(j<n-1 and s.find(dp[i][j+1].second) == s.end()){
            cnt+=dp[i][j+1].first;
        }
        return cnt;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(n,{0,0}));
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        int grp = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] and !visited[i][j]){
                    int cnt = dfs(grid,visited,i,j,n);
                    dfs2(grid,dp,i,j,n,cnt,grp);
                    grp++;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans = max(ans , dp[i][j].first);
                if(!dp[i][j].first){
                    ans = max(ans , dfs3(dp,i,j,n));
                }
            }
        }
        return ans;
    }
};