class Solution {
public:
    int coinChange(vector<int>& coins, int a) {
        int n = coins.size();
        int dp[a+1];
        dp[0] = 0;
        sort(coins.begin(),coins.end());
        for(int i=1;i<=a;i++){
            dp[i] = INT_MAX;
            for(auto j:coins){
                if(i-j>=0){
                    if(dp[i-j]!=INT_MAX){
                        dp[i] = min(dp[i],1+dp[i-j]);
                    }
                }else break;
            }
        }
        if(dp[a]==INT_MAX) return -1;
        return dp[a];
    }
};