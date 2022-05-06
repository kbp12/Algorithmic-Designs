class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0, n = s.length(),j=0;
        while(j<n){
            s[i] = s[j];
            if(i>0 && s[i-1]==s[i]) i-=2;
            i++; j++;
        }
        return s.substr(0,i);
    }
};