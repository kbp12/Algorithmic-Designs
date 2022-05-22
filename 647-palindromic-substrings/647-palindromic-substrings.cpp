class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i] = true;
            if(i!=n-1 && s[i]==s[i+1]){
                dp[i][i+1] = true;
            }
        }
        for(int d=2;d<n;d++){
            for(int i=0;i<n-d;i++){
                if(dp[i+1][i+d-1] && s[i]==s[i+d]){
                    dp[i][i+d] = true;
                }
            }
        }
        int c = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]) c++;
            }
        }
        return c;
    }
};