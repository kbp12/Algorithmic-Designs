class Solution {
public:
    int countHomogenous(string s) {
        int n = s.length(), ans = 0, i = 0, mod = 1e9+7;
        while(i<n){
            long long c = 1;
            while(i<n-1 && s[i]==s[i+1]){i++; c++;}
            i++;
            long long a = c*(c+1)/2;
            int t = a%mod;
            ans = (ans+t)%mod;
        }
        return ans;
    }
};