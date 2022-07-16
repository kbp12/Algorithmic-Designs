class Solution {
public:
    int modd = 1e9+7;
    vector<vector<vector<int>>>dp;
    
    int dfs(int i,int j, int m, int n, int maxMove, int moves){
        if(moves>maxMove) return 0;
        if(i<0 || j<0 || i>=m || j>=n) return 1;
        if(dp[i][j][moves]!=-1) return dp[i][j][moves];
        int ways = 0;
        ways = (ways+dfs(i-1,j,m,n,maxMove,moves+1))%modd;
        ways = (ways+dfs(i+1,j,m,n,maxMove,moves+1))%modd;
        ways = (ways+dfs(i,j-1,m,n,maxMove,moves+1))%modd;
        ways = (ways+dfs(i,j+1,m,n,maxMove,moves+1))%modd;
        return dp[i][j][moves] = ways;
    }
    
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        dp = vector<vector<vector<int>>> (51,vector<vector<int>>(51,vector<int>(51,-1)));
        return dfs(sr,sc,m,n,maxMove,0);
    }
};