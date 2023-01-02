class Solution {
public:
    bool detectCapitalUse(string word) {
        char first = word[0];
        int n = word.length();
        if(n==1) return true;
        bool capital = false;
        int c = word[0]-'A';
        if(c>=0 && c<26)
            capital = true;
        bool second = false;
        c = word[1]-'A';
        if(c>=0 && c<26)
            second = true;
        if(second && !capital) return false;
        for(int i=2;i<n;i++){
            int t = word[i]-'A';
            if(capital && second){
                 if(t<0 || t>25){
                     return false;
                 }
            }else if(capital){
                if(t>=0 && t<26)
                    return false;
            }else{
                if(t>=0 && t<26)
                    return false;
            }
        }
        return true;
    }
};