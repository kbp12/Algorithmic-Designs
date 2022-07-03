class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1,0);
        int mod = 1e9+7;
        dp[1] = 1;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=min(n,i+forget-1);j++){
                if(j>=(i+delay)){
                    dp[j] = (dp[i]+dp[j])%mod;
                }
            }
        }
        int ans = 0;
        for(int i=n;i>=max(0,n-forget+1);i--)
            ans = (ans+dp[i])%mod;
        return ans;
    }
};