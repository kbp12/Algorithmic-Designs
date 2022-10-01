class Solution {
public:
    int numDecodings(string str) {
        int n = str.size(), mod = 1e9+7;
        int f,s;
        f=1;
        if(str[0]=='0') s = 0;
        else if(str[0]=='*') s = 9;
        else s = 1;
        for(int i=2;i<=n;i++){
            int c = 0;
            if(str[i-1]=='*' and str[i-2]=='*'){
                c = (((long long)s*9)%mod + ((long long)f*15)%mod)%mod;
            }else if(str[i-1]=='*'){
                if(str[i-2]=='1') c = ((long long)f*9)%mod;
                if(str[i-2]=='2') c = ((long long)f*6)%mod;
                c = (c + ((long long)s*9)%mod)%mod;
            }else if(str[i-2]=='*'){
                int a = 1;
                if(str[i-1]>='0' and str[i-1]<'7'){
                    a++;
                }
                c = ((long long)f*a)%mod;
                if(str[i-1]!='0')
                    c = (s+c)%mod;
            }else{
                if(str[i-1]!='0') c = s;
                int a = stoi(str.substr(i-2,2));
                if(a<27 and str[i-2]!='0') c = (c+f)%mod;
            }
            f = s; 
            s = c;
        }
        return s;
    }
};