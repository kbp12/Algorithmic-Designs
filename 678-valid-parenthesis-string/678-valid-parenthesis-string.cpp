class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int l = 0, r = 0, stars = 0;
        //cheecking if i am maximizing left count
        for(int i=0;i<n;i++){
            if(s[i]=='*')   stars++;
            else if(s[i]==')')  r++;
            else    l++;
            if(r-l>stars) return false;
        }
        l=0,r=0,stars=0;
        //maximizing right count
        for(int i=n-1;i>=0;i--){
            if(s[i]=='*') stars++;
            else if(s[i]==')')  r++;
            else l++;
            if(l-r>stars) return false;
        }
        return true;
    }
};