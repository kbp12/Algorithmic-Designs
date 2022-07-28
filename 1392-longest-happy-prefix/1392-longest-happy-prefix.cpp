class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int>dp(n+1,0);
        int i =1, l = 0;
        while(i<n){
            if(s[i]==s[l]){
                l++;
                dp[i] = l;
                i++;
            }else{
                if(l==0){
                    dp[i] = 0; i++;
                }else{
                    l = dp[l-1];
                }
            }
        }
        return s.substr(0,dp[n-1]);
    }
};