class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), mod = 1e9+7;
        vector<int>dp(n+1,0);
        dp[0] = 1;
        if(s[0]=='0') dp[1] = 0;
        else if(s[0]=='*') dp[1] = 9;
        else dp[1] = 1;
        for(int i=2;i<=n;i++){
            int ways1 = 0, ways2 = 0,ways3 = 0;
            if(s[i-1]=='*' and s[i-2]=='*'){
                dp[i] = (((long long)dp[i-1]*9)%mod + ((long long)dp[i-2]*15)%mod)%mod;
            }else if(s[i-1]=='*'){
                if(s[i-2]=='1') dp[i] = ((long long)dp[i-2]*9)%mod;
                if(s[i-2]=='2') dp[i] = ((long long)dp[i-2]*6)%mod;
                dp[i] = (dp[i] + ((long long)dp[i-1]*9)%mod)%mod;
            }else if(s[i-2]=='*'){
                int a = 1;
                if(s[i-1]>='0' and s[i-1]<'7'){
                    a++;
                }
                dp[i] = ((long long)dp[i-2]*a)%mod;
                if(s[i-1]!='0')
                    dp[i] = (dp[i-1]+dp[i])%mod;
            }else{
                if(s[i-1]!='0') dp[i] = dp[i-1];
                int a = stoi(s.substr(i-2,2));
                if(a<27 and s[i-2]!='0') dp[i] = (dp[i]+dp[i-2])%mod;
            }
        }
        return dp[n];
    }
};