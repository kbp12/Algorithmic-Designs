class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9+7;
        string s = "";
        for(int i=n;i>=1;i--){
            int a = i;
            while(a){
                if(a&1){
                    s+='1';
                }else{
                    s+='0';
                }
                a/=2;
            }
        }
        int val = 0,mul = 1;
        for(int j=0;j<s.size();j++){
            val = (val+(s[j]-'0')*mul)%mod;
            mul*=2;
            mul%=mod;
        }
        return val;
    }
};