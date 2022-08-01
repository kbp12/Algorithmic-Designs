class Solution {
public:
    vector<vector<int>>dp;
    bool ispoint(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    
    int bfs(int i,int j,int n,int m,vector<vector<int>>&matrix){
        if(dp[i][j]) return dp[i][j];
        int c = 1;
        if(ispoint(i-1,j,n,m) and matrix[i-1][j]>matrix[i][j]) c = max(bfs(i-1,j,n,m,matrix)+1,c);
        if(ispoint(i+1,j,n,m) and matrix[i+1][j]>matrix[i][j]) c = max(bfs(i+1,j,n,m,matrix)+1,c);
        if(ispoint(i,j-1,n,m) and matrix[i][j-1]>matrix[i][j]) c = max(bfs(i,j-1,n,m,matrix)+1,c);
        if(ispoint(i,j+1,n,m) and matrix[i][j+1]>matrix[i][j]) c = max(bfs(i,j+1,n,m,matrix)+1,c);
        return dp[i][j] = c;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        dp = vector<vector<int>> (n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bfs(i,j,n,m,matrix);
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};