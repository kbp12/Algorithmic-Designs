class Solution {
public:
    int n,m,dp[10005][20];
    int C[10005][20];
    int idealArrays(int n, int m) {
        int mod = 1e9+7;
        for(int i=1; i<=m; i++) {
		    dp[i][1]=(dp[i][1]+1)%mod;
		    for(int j=i+i; j<=m; j+=i) {
			    for(int k=1; k<=18; k++) {
				    dp[j][k]=(dp[j][k]+dp[i][k-1])%mod;
			    }
		    }
	    }
	    for(int i=0; i<=n; i++) {
		    C[i][0]=1;
		    for(int j=1; j<=min(i,18); j++) {
			    C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		    }
	    }
	    long long ans=0;
	    for(int i=1; i<=m; i++) {
		    for(int j=1; j<=18; j++) {
			    ans=(ans+1ll*dp[i][j]*C[n-1][j-1]%mod)%mod;
		    }
	    }
	    return ans;
    }
};