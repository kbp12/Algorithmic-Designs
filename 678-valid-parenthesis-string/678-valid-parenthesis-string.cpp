class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int stars = 0, left = 0, right = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                stars++;
            }else{
                if(s[i]=='('){
                    left++;
                }else{
                    right++;
                }
            }
            if(right-left>stars) return false;
        }
        stars = 0, left = 0, right = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='*'){
                stars++;
            }else{
                if(s[i]=='('){
                    left++;
                }else{
                    right++;
                }
            }
            if(left-right>stars) return false;
        }
        return true;
    }
};