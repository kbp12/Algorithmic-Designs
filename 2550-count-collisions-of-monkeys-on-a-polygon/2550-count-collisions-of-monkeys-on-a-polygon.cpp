class Solution {
public:
    int monkeyMove(int n) {
        int mod = 1e9+7;
        long long ans = 1;
        int k = n/100000;
        int m = n%100000;
        if(k>0){
            for(int i=1;i<=100000;i++){
                ans = (ans*2)%mod;
            }
        }
        long long res = ans;
        for(int i=2;i<=k;i++){
            res = (res*ans)%mod;
        }
        for(int i=1;i<=m;i++){
            res = (res*2)%mod;
        }
        return (res+mod-2)%mod;
    }
};