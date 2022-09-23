class Solution {
public:
    int concatenatedBinary(int n) {
        int ans = 1, mod = 1e9+7;
        string s = "";
        for(int i=1;i<=n;i++){
            int a = i;
            string s2 = "";
            while(a){
                if(a&1){
                    s2+='1';
                }else{
                    s2+='0';
                }
                a/=2;
            }
            reverse(s2.begin(),s2.end());
            s+=s2;
        }
        long long val = 0,mul = 1;
            for(int j=s.size()-1;j>=0;j--){
                int b = (s[j]-'0');
                val = (val+ b*mul)%mod;
                mul= (mul*2)%mod;
            }
            val%=mod;
            ans=val;
        return ans;
    }
};