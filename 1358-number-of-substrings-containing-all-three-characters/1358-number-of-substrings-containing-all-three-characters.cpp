class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length(),a=0,b=0,c=0;
        int ans=0;
        for(int i=0,j=0;j<n;j++){
            if(s[j]=='a') a++;
            else if(s[j]=='b') b++;
            else c++;
            while(a && b && c){
                ans+= n-j;
                if(s[i]=='a') a--;
                else if(s[i]=='b') b--;
                else c--;
                i++;
            }
        }
        return ans;
    }
};