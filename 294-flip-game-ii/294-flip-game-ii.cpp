class Solution {
public:    
    bool canWin(string s) {
        for(int i=1;i<s.size();i++){
            if(s[i]=='+' and s[i-1]=='+'){
                s[i]='-';
                s[i-1]='-';
                bool isit = !canWin(s);
                s[i]='+';
                s[i-1]='+';
                if(isit) return true;
            }
        }
        return false;
    }
};