class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            if(i!=n-1 && s[i]==s[i+1])
                dp[i+1][i] = true;
        }
        for(int i=2;i<n;i++){
            for(int j=i-2;j>=0;j--){
                if(dp[i-1][j+1]==true && s[i]==s[j])
                    dp[i][j] = true;
            }
        }
        int l = 0;
        string ans = "";
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(dp[i][j]==true){
                    if(i-j+1>l){
                        l = i-j+1;
                        ans = s.substr(j,i-j+1);
                    }
                }
            }
        }
        return ans;
    }
};