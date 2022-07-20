class Solution {
public:
    int numRollsToTarget(int n, int k, int t) {
        vector<vector<int>>dp(t+1,vector<int>(n+1,0));
        dp[0][0] = 1;
        int mod = 1e9+7;
        for(int i=1;i<=t;i++){
            for(int j=1;j<=n;j++){
                int p = 1;
                while(p<=k && i-p>=0){
                    dp[i][j] = (dp[i][j]+dp[i-p][j-1])%mod;
                    p++;
                }
            }
        }
        return dp[t][n];
    }
};