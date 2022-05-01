class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="", s2="";
        int n = s.length(), m = t.length();
        int i = n-1;
        int c = 0;
        while(i>=0){
            if(s[i]!='#'){ 
                if(c==0)s1.push_back(s[i]);
                else c--;
                i--;
            }else{
                c++; i--;
            }
        }
        c=0;
        i = m-1;
        while(i>=0){
            if(t[i]!='#'){
                if(c==0)s2.push_back(t[i]);
                else c--;
                i--;
            }else{
                c++; i--;
            }
        }
        cout<<s1<<" "<<s2;
        if(s1==s2) return true;
        return false;
    }
};