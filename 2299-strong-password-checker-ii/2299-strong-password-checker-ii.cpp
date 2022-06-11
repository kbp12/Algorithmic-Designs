class Solution {
public:
    bool strongPasswordCheckerII(string p) {
        int n = p.length();
        if(n<8) return false;
        for(int i=1;i<n;i++){
            if(p[i]==p[i-1]) return false;
        }
        bool dig = true;
        bool small = true;
        bool big = true;
        bool ch = true;
        for(int i=0;i<n;i++){
            if(p[i]>='0' && p[i]<='9'){
                dig = false;
            }
            if(p[i]>='a' && p[i]<='z'){
                small = false;
            }
            if(p[i]>='A'  && p[i]<='Z'){
                big = false;
            }
            if(p[i]=='!'||p[i]=='@'||p[i]=='#'||p[i]=='$'||p[i]=='%'||p[i]=='^'||p[i]=='&'||p[i]=='*'||p[i]=='('||p[i]==')'||p[i]=='-'||p[i]=='+'){
                ch = false;
            }
        }
        if(dig||small||big||ch){
            return false;
        }
        return true;
    }
};