class Solution {
public:
    int maxNiceDivisors(int p) {
        if(p==1) return 1;
        int mod = 1e9+7;
        int div = p/3;
        int rem = p%3;
        if(rem==1){
            div--;
            rem++;
        }else if(rem==2){
            rem--;
        }
        int maxi = min(p,10000);
        vector<long long>dp(maxi+1);
        dp[1] = 3;
        for(int i=2;i<=maxi;i++){
            dp[i] = (dp[i-1]*3)%mod;
        }
        long long ans = 1;
        while(div){
            if(div>=maxi){
                ans = (ans*dp[maxi])%mod;
                div-=maxi;
            }else{
                ans = (ans*dp[div])%mod;
                div = 0;
            }
        }
        if(rem==2){
            ans = (ans*4)%mod;
        }else if(rem==1){
            ans = (ans*2)%mod;
        }
        return (int)ans;
    }
};