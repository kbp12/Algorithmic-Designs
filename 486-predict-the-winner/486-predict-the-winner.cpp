class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        long long sum[n+1]; sum[0] = 0;
        for(int i=0;i<n;i++) sum[i+1] = sum[i]+nums[i];
        long long dp[n][n];
        for(int i=0;i<n;i++){
            dp[i][i] = nums[i];
            if(i!=n-1) dp[i][i+1] = max(nums[i],nums[i+1]);
        }
        for(int l=2;l<n;l++){
            for(int i=0;i<n-l;i++){
                dp[i][i+l] = sum[i+l+1]-sum[i]-min(dp[i+1][i+l],dp[i][i+l-1]);
            }
        }
        if(dp[0][n-1]>=(sum[n]-dp[0][n-1])) return true;
        return false;
    }
};