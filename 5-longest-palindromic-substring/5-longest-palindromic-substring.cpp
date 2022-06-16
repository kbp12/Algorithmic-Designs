class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i] = true;
            if(i!=n-1 && s[i]==s[i+1]){
                dp[i][i+1] = true;
            }
        }
        for(int len = 2;len<n;len++){
            for(int i=0;i+len<n;i++){
                if(s[i]==s[i+len] && dp[i+1][i+len-1]){
                    dp[i][i+len] = true;
                }
            }
        }
        int maxlen = 0;
        string ans = "";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j] and maxlen<j-i+1){
                    maxlen = j-i+1;
                    ans = s.substr(i,j-i+1);
                }
            }
        }
        return ans;
    }
};