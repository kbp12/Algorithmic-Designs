class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,0);
        dp[1] = arr[0];
        for(int i=2;i<=n;i++){
            int ans = 0, maxi = arr[i-1];
            for(int j=1;j<=k && i-j>=0;j++){
                maxi = max(arr[i-j],maxi);
                ans = max(ans,dp[i-j]+j*maxi);
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};