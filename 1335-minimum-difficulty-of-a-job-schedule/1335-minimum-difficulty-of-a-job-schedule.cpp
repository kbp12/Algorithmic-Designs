class Solution {
public:
        
    int minDifficulty(vector<int>& arr, int d) {
        int n = arr.size();
        if(n<d) return -1;
        vector<vector<int>>dp(n+1,vector<int>(d+1,300006));
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            for(int dd=1;dd<=d;dd++){
                int maxi = arr[i-1];
                for(int j=i;j>=1;j--){
                    maxi = max(maxi,arr[j-1]);
                    dp[i][dd] = min(dp[i][dd] , dp[j-1][dd-1]+maxi);
                }
            }
        }
        return dp[n][d];
    }
};