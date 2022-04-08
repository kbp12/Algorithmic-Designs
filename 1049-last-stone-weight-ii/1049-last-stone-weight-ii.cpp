class Solution {
public:
    int lastStoneWeightII(vector<int>& nums) {
        int total = 0;
        for(auto it:nums) total+= it;
        int m = total/2;
        int n = nums.size();
        int dp[n+1][m+1];
        for(int i=0;i<=m;i++) dp[0][i] = 0;
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(j<nums[i-1]){
                    dp[i][j] = dp[i-1][j]; 
                }else{
                    dp[i][j] = max(dp[i-1][j],nums[i-1]+dp[i-1][j-nums[i-1]]);
                }
                cout<<dp[i][j]<<" ";
            }
        }
        return (total-dp[n][m])-dp[n][m];
    }
};