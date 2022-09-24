class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n-1)%(k-1)) return -1;
        vector<int>pref(n+1);
        for(int i=1;i<=n;i++){
            pref[i] = pref[i-1]+stones[i-1];
        }
        vector<vector<int>>dp(n,vector<int>(n));
        for(int l=k;l<=n;l++){
            for(int i=0;i<=(n-l);i++){
                int j = i+l-1;
                dp[i][j] = INT_MAX;
                for(int x=i;x<j;x+=(k-1)){
                    dp[i][j] = min(dp[i][j],dp[i][x]+dp[x+1][j]);
                }
                if((l-1)%(k-1)==0){
                    dp[i][j]+=(pref[j+1]-pref[i]);
                }
            }
        }
        return dp[0][n-1];
    }
};