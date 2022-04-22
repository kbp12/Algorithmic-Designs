class Solution {
public:
    bool canBeValid(string s, string l) {
        int n = s.length();
        if(n%2) return false;
        int open = 0;
        int start = 0;
        int end = 0;
        for(int i=0;i<n;i++){
            if(l[i]=='0'){
                open++;
            }else{
                if(s[i]=='('){
                    start++;
                }else{
                    end++;
                }
            }
            if((end-start)>open) return false;
        }
        open = 0;
        start = 0;
        end = 0;
        for(int i=n-1;i>=0;i--){
            if(l[i]=='0'){
                open++;
            }else{
                if(s[i]=='('){
                    start++;
                }else{
                    end++;
                }
            }
            if((start-end)>open) return false;
        }
        return true;
    }
};