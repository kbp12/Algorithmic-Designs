class Solution {
public:
    bool checkRecord(string s) {
        int n = s.length();
        bool a = false;
        for(int i=0;i<n;i++){
            if(s[i]=='A'){
                if(a) return false;
                a = true;
            }else if(s[i]=='L' && i>=2 && s[i-1]=='L' && s[i-2]=='L'){
                return false;
            }
        }
        return true;
    }
};