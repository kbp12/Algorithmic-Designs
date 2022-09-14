class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>>dp(2,vector<long long>(n,INT_MIN));
        dp[0][0] = nums[0];
        long long ans = dp[0][0];
        for(int i=1;i<n;i++){
            dp[0][i] = max(dp[1][i-1]+nums[i],(long long)nums[i]);
            if(i<2){
                dp[1][i] = dp[0][i-1]-nums[i];
            }else{
                dp[1][i] = max(dp[0][i-1]-nums[i],(long long)nums[i-1]-nums[i]);
            }
            //dp[1][i] = max(dp[0][i-1]-nums[i],(long long)-nums[i]);
            ans = max({ans,dp[0][i],dp[1][i]});
        }
        return ans;
    }
};