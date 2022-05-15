class Solution {
public:
    int countTexts(string s) {
        int n = s.length();
        vector<int>dp(n);
        dp[0] =1;
        int mod = 1e9+7;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                if(i==1){
                    dp[i] = 2;
                }else{
                    if(s[i]==s[i-2]){
                        if(i==2){
                            dp[i] = 4;
                        }else{
                            if(s[i]==s[i-3] && (s[i]=='7'||s[i]=='9')){
                                if(i==3){
                                    dp[i] = 8;
                                }else{
                                    dp[i] = (((dp[i-1]+dp[i-2])%mod+dp[i-3])%mod+dp[i-4])%mod;
                                }
                            }else{
                                dp[i] = ((dp[i-1]+dp[i-2])%mod+dp[i-3])%mod;
                            }
                        }
                    }else{
                        dp[i] = (dp[i-1]+dp[i-2])%mod;
                    }
                }
            }else{
                dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
};