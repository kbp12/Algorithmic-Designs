class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>>dp(n,vector<long long>(2,INT_MIN));
        dp[0][0] = nums[0];
        long long ans = dp[0][0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][1]+nums[i],(long long)nums[i]);
            if(i<2){
                dp[i][1] = dp[i-1][0]-nums[i];
            }else{
                dp[i][1] = max(dp[i-1][0]-nums[i],(long long)nums[i-1]-nums[i]);
            }
            ans = max({ans,dp[i][0],dp[i][1]});
        }
        return ans;
    }
};