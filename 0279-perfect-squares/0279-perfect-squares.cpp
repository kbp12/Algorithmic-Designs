class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            int j = 1;
            while(j*j<=i){
                dp[i] = min(dp[i] , 1+dp[i-j*j]);
                j++;
            }
        }
        return dp[n];
    }
};