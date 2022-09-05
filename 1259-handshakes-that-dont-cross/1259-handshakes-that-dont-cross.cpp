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
            long long a = ways(i+1,k-1);
            long long b = ways(k+1,j);
            long long c = a*b;
            c = c%mod;
            if(a==0){
                ans = (ans+b)%mod;
            }else if(b==0){
                ans = (ans+a)%mod;
            }else
                ans = (ans+c)%mod;
        }
        //cout<<i<<" "<<j<<" "<<ans<<endl;
        return dp[j-i+1] = ans;
    }
    int numberOfWays(int n) {
        dp = vector<int>(n+1,-1);
        return ways(0,n-1);
    }
};