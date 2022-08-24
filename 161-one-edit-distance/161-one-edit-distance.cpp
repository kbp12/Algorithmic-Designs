class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n-m==1){
            int i = 0, j = 0;
            int c = 0;
            while(i<n and j<m){
                if(s[i]==t[j]){
                    i++; j++;
                }else{
                    i++;
                    c++;
                }
            }
            if(c==1 or m==0 or n-i==1) return true;
        }else if(n==m){
            int i=0,j=0;
            int c = 0;
            while(i<n and j<m){
                if(s[i]!=t[j]){
                    c++;
                }
                i++; j++;
            }
            if(c==1) return true;
        }else if(m-n==1){
            int i=0, j = 0;
            int c = 0;
            while(i<n and j<m){
                if(s[i]==t[j]){
                    i++; j++;
                }else{
                    j++;
                    c++;
                }
            }
            if(c==1 or n==0 or m-j==1) return true;
        }
        return false;
    }
};