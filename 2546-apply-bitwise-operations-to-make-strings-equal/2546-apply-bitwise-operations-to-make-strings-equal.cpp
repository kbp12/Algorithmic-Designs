class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        int n = s.size() , oz = 0, zo = 0, z = 0, o = 0;
        for(int i=0;i<n;i++){
            if(s[i] != t[i]){
                if(s[i] == '0') zo++;
                else oz++;
            }else{
                if(t[i] == '1') o++;
                else z++;
            }
        }
        if(oz and o) return true;
        if(oz and zo) return true;
        if(zo and o) return true;
        if(s == t) return true;
        return false;
    }
};