class Solution {
public:
    int numWays(int n, int k) {
        if(n==1) return k;
        vector<vector<int>>dp(k,vector<int>(n,1));
        for(int i=0;i<k;i++){
            dp[i][1] = k;
        }
        int first = k;
        int sec = k*k;
        int temp;
        for(int j=2;j<n;j++){
            temp = 0;
            for(int i=0;i<k;i++){
                dp[i][j] = first+sec-dp[i][j-2]-dp[i][j-1];
                temp+=dp[i][j];
            }
            first = sec;
            sec = temp;
        }
        return sec;
    }
};