class Solution {
public:
    bool PredictTheWinner(vector<int>& a) {
         int n = a.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    dp[0][0] = a[0];
    int sum = a[0];
    for(int i=1;i<n;i++){
        dp[i][i] = a[i];
        sum+=a[i];
        dp[i-1][i] = max(a[i-1],a[i]);
    }
    
    for(int len = 3;len<=n;len++){
        for(int i=0;i<n;i++){
            int j = i+len-1;
            if(j>=n) break;
            dp[i][j] = max({
                a[i]+min({
                    dp[i+2][j],dp[i+1][j-1]
                }),
                a[j]+min({
                    dp[i][j-2],dp[i+1][j-1]
                })
            });
        }
    }
        //cout<<dp[0][n-1]<<endl;
    int b  = 2*dp[0][n-1];
        if(b>=sum) return true;
        return false;
        
    }
};