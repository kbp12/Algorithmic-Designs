class Solution {
public:
    int checkRecord(int n) {
        int modd = 1e9+7;
        int dp[4][100001];
        dp[0][0] = 0, dp[1][0] = 0, dp[2][0] = 0, dp[3][0] = 0;
        dp[0][1] = 1, dp[1][1] = 1, dp[2][1] = 1, dp[3][1] = 3;
        dp[0][2] = 3, dp[1][2] = 3, dp[2][2] = 2, dp[3][2] = 8;
        dp[0][3] = 8, dp[1][3] = 7, dp[2][3] = 4, dp[3][3] = 19;
        for(int i=4;i<=n;i++){
            dp[0][i] = dp[3][i-1];
            dp[1][i] = ((dp[0][i-1]+dp[2][i-1])%modd+(dp[0][i-2]+dp[2][i-2])%modd)%modd;
            dp[2][i] = ((dp[2][i-1]+dp[2][i-2])%modd + dp[2][i-3])%modd;
            dp[3][i] = ((dp[0][i]+dp[1][i])%modd+dp[2][i])%modd;
        }
        return dp[3][n];
    }
};