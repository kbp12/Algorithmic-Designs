class Solution {
public:
    int dp[1005][1005] = {};
    int mod = 1e9+7;
    int rearrangeSticks(int n, int k) {
        if(k==0 or k>n) return 0;
        if(n==1 or n==2) return 1;
        if(dp[n][k]) return dp[n][k];
        long long ans = rearrangeSticks(n-1,k-1)%mod;
        ans  = (ans + (long long)(n-1)* rearrangeSticks(n-1,k))%mod;
        return dp[n][k] = ans;
    }
};