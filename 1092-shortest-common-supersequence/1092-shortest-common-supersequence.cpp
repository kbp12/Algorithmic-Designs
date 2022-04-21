class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<pair<int,string>>>dp(n+1,vector<pair<int,string>>(m+1));
        for(int i=0;i<=n;i++){dp[i][0].first=0; dp[i][0].second="";}
        for(int j=0;j<=m;j++){dp[0][j].first=0; dp[0][j].second="";}
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j].first = 1+dp[i-1][j-1].first;
                    dp[i][j].second = dp[i-1][j-1].second+s1[i-1];
                }else{
                    if(dp[i-1][j].first>dp[i][j-1].first){
                        dp[i][j].first = dp[i-1][j].first;
                        dp[i][j].second = dp[i-1][j].second;
                    }else{
                        dp[i][j].first = dp[i][j-1].first;
                        dp[i][j].second = dp[i][j-1].second;
                    }
                }
            }
        }
        int siz = dp[n][m].first;
        string s = dp[n][m].second;
        string ans = "";
        int i=0,j=0,k=0;
        while(k<siz){
            while(s1[i]!= s[k]){ans+= s1[i];i++;}
            while(s2[j]!=s[k]){ans+= s2[j];j++;}
            ans+= s1[i];
            i++;j++;k++;
        }
        while(i<n){ans+= s1[i]; i++;}
        while(j<m){ans+= s2[j]; j++;}
        return ans;
    }
};