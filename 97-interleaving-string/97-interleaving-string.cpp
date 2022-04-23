class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(), siz = s3.length();
        if(n+m!=siz) return false;
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[n][m] = true;
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(dp[i][j]){
                    if(i!=0 && s3[i+j-1]==s1[i-1]) dp[i-1][j] = true;
                    if(j!=0 && s3[i+j-1]==s2[j-1]) dp[i][j-1] = true;
                }
            }
        }
        return dp[0][0];
    }
};