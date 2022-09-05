class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(2,vector<int>(n,0));
        dp[0][0] = nums[0];
        dp[1][0] = nums[0]*nums[0];
        int ans = dp[1][0];
        for(int i=1;i<n;i++){
            dp[0][i] = max(nums[i],dp[0][i-1]+nums[i]);
            dp[1][i] = max({nums[i]*nums[i],dp[0][i-1]+nums[i]*nums[i],dp[1][i-1]+nums[i]});
            ans = max({ans,dp[0][i],dp[1][i]});
        }
        return ans;
    }
};