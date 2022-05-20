class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size();
        if(v[0][0] || v[m-1][n-1]) return 0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(v[i-1][j-1]==0){dp[i][j] = dp[i-1][j]+dp[i][j-1];}
            }
        }
        return dp[m][n];
    }
};