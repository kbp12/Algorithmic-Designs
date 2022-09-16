class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n = nums.size(), m = mul.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));
        for(int i=1;i<=m;i++){
            dp[i][0] = dp[i-1][0]+mul[i-1]*nums[n-i];
            for(int j=1;j<i;j++){ 
               dp[i][j] = max(dp[i-1][j-1]+mul[i-1]*nums[j-1] , dp[i-1][j]+mul[i-1]*nums[n-(i-j)]);
            }
            dp[i][i] = dp[i-1][i-1]+mul[i-1]*nums[i-1];
        }
        int ans = INT_MIN;
        for(int i=0;i<=m;i++) ans = max(ans,dp[m][i]);
        return ans;
    }
};