class Solution {
public:
    string maximumBinaryString(string s) {
        int n = s.length();
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                c++;
            }
        }
        int i=0;
        while(i<n && s[i]=='1'){
               i++;
        }
        for(int j=1;j<c && i<n;j++){
            s[i] = '1'; i++;
        }
        s[i] = '0'; i++;
        while(i<n){
            s[i] = '1'; i++;
        }
        return s;
    }
};