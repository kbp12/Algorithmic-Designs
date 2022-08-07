class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>>dp(5,vector<int>(n+1,0));
        dp[0][1] = 1, dp[1][1] = 1, dp[2][1] = 1, dp[3][1] = 1, dp[4][1] = 1;
        int mod = 1e9+7;
        for(int i=2;i<=n;i++){
            dp[0][i] = ((dp[1][i-1]+dp[2][i-1])%mod+dp[4][i-1])%mod;
            dp[1][i] = (dp[0][i-1]+dp[2][i-1])%mod;
            dp[2][i] = (dp[1][i-1]+dp[3][i-1])%mod;
            dp[3][i] = dp[2][i-1];
            dp[4][i] = (dp[2][i-1]+dp[3][i-1])%mod;
        }
        return ((((dp[0][n]+dp[1][n])%mod+dp[2][n])%mod+dp[3][n])%mod+dp[4][n])%mod;
    }
};