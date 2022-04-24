class Solution {
public:
    int numSub(string s) {
        int n = s.length(), ans = 0, i=0, mod = 1e9+7;
        while(i<n){
            long long c = 0;
            while(i<n && s[i]=='1'){i++; c++;}
            i++;
            c = c*(c+1)/2;
            int a = c%mod;
            ans = (ans+a)%mod;
        }
        return ans;
    }
};