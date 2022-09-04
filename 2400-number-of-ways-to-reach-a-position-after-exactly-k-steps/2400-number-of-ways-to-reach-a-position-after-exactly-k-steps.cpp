class Solution {
public:
    int numberOfWays(int s, int e, int k) {
        int mod = 1e9+7;
        int d = abs(e-s);
        if(d>k or abs(k-d)%2) return 0;
        if(d==k) return 1;
        vector<vector<int>>dp(k+1,vector<int>(2*k+1,0));
        dp[0][k] = 1;
        for(int i=1;i<=k;i++){
            dp[i][0] = dp[i-1][1];
            dp[i][2*k] = dp[i-1][2*k-1];
            for(int j=1;j<=(2*k-1);j++){
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%mod;
            }
        }
        return dp[k][k+d];
    }
};