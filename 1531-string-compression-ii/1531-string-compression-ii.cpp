class Solution {
public:
    int dp[105][105];
    int n;
    int solve(int i, string &s, int k){
        if(k<0) return n;
        if(i>=n or n-i<=k) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int ans = 100;
        int v[26] = {0};
        int cnt = 0;
        for(int j=i;j<n;j++){
            cnt = max(cnt , ++v[s[j]-'a']);
            int toadd = 0;
            if(cnt==1) toadd = 0;
            else if(cnt<10) toadd = 1;
            else if(cnt==100) toadd = 3;
            else toadd = 2;
            ans = min(ans , 1 + toadd + solve( j+1 , s , k - ((j-i+1) - cnt)));
        }
        return dp[i][k] = ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,s,k);
    }
};