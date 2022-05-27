class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(mat[i-1][j-1]=='1'){
                    dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                ans = max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};