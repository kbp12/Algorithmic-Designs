class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size(),j;
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int l=1;l<=n;l++){
            for(int i=1;i<=(n+1-l);i++){
                j = i+l-1;
                for(int k=i;k<=j;k++){
                    dp[i][j] = max(dp[i][j],nums[i-1]*nums[j+1]*nums[k] + dp[i][k-1]+dp[k+1][j]);
                }
            }
        }
        return dp[1][n];
    }
};