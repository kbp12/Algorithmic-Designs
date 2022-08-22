class Solution {
public:
    bool makePalindrome(string s) {
        int j = s.size()-1, i = 0, c = 0;
        while(i<=j){
            if(s[i]==s[j]){
                i++; j--;
            }else{
                c++;
                i++; j--;
            }
        }
        return c<3;
    }
};