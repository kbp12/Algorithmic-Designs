class Solution {
public:
    int coinChange(vector<int>& coins, int am) {
        int n = coins.size();
        vector<vector<int>>dp(am+1,vector<int>(n+1,0));
        for(int i=1;i<=am;i++) dp[i][0] = INT_MAX;
        for(int i=1;i<=am;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = dp[i][j-1];
                if(i-coins[j-1]>=0 && dp[i-coins[j-1]][j]!=INT_MAX){
                    dp[i][j] = min(dp[i][j],1+dp[i-coins[j-1]][j]);
                } 
            }
        }
        if(dp[am][n]==INT_MAX) return -1;
        return dp[am][n];
    }
};