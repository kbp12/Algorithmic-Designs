class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        int n = stones.size(); 
        vector<int>sum(n+1,0);
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            sum[i] = stones[i]+sum[i+1];
            if(i==n-1)dp[n-1] = sum[n-1];
            else if(i==n-2) dp[n-2] = max(sum[n-2],sum[n-2]-sum[n-1]);
            // else if(i==n-3) dp[n-3] = max(sum[n-3],max(sum[n-3]-dp[n-2],sum[n-3]-dp[n-1]));
            else dp[i] = max(sum[i]-dp[i+1],max(sum[i]-dp[i+2],sum[i]-dp[i+3]));
        }
        if(dp[0]>sum[0]-dp[0]) return "Alice";
        else if(dp[0]<sum[0]-dp[0]) return "Bob";
        return "Tie";
    }
};

