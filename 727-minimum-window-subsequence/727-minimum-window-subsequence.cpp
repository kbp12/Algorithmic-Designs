class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int j=0;j<=n;j++){
            dp[0][j] = j+1;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(t[i-1] == s[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        int st = 0, l = n+1;
        for(int j=1;j<=n;j++){
            if(dp[m][j]){
                if(j-dp[m][j]+1<l){
                    st = dp[m][j]-1;
                    l = j-dp[m][j]+1;
                }
            }
        }
        if(l==n+1) return "";
        return s.substr(st,l);
    }
};