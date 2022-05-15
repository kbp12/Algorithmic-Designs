class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int ans = 0;
        int j=0;
        int c= 0;
        for(int i=0;i<n;i++){
            while(j<n && j-i<k){
                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u') c++;
                j++;
            }
            ans = max(ans,c);
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') c--;
        }
        return ans;
    }
};