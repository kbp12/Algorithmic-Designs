class Solution {
public:
    int removePalindromeSub(string s) {
        int i=0, j = s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                break;
            }
            i++; j--;
        }
        if(i>j) return 1;
        return 2;
    }
};