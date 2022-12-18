class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>>dp(n,vector<long long>(2 , 0));
        long long ans = nums[0];
        dp[0][1] = nums[0];
        for(int i=1;i<n;i++){
            // adding this element into the sequence , not adding this element into the sequence
            dp[i][0] = max(dp[i-1][0] , dp[i-1][1] - nums[i]);
            dp[i][1] = max(dp[i-1][1] , dp[i-1][0] + nums[i]);
            ans = max(ans , dp[i][1]);
        }
        return ans;
    }
};