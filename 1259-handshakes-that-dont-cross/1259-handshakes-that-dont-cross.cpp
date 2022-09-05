class Solution {
public:
    vector<int>dp;
    int mod = 1e9+7;
    int ways(int i, int j){
        if(i>=j) return 0;
        if(j==i+1){
            dp[j-i+1] = 1;
            return 1;
        }
        if(dp[j-i+1]!=-1) return dp[j-i+1];
        int ans = 0;
        for(int k=i+1;k<=j;k+=2){
            int a = ways(i+1,k-1);
            a = max(a,1);
            int b = ways(k+1,j);
            b = max(b,1);
            int c = ((long long)a*b)%mod;
            ans = (ans+c)%mod;
        }
        return dp[j-i+1] = ans;
    }
    int numberOfWays(int n) {
        dp = vector<int>(n+1,-1);
        return ways(0,n-1);
    }
};