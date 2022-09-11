class Solution {
public:
    int waysToDistribute(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        dp[0][0] = 1;
        int mod = 1e9+7;
        for(int candy = 1; candy<=n ; candy++){
            for (int bag=1; bag<=k ; bag++){
                dp[candy][bag] = (dp[candy-1][bag-1] + ((long long)bag*dp[candy-1][bag])%mod)%mod;
            }
        }
        return dp[n][k];
    }
};