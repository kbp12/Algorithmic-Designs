class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int z = 0, ans;
        for(int i=0;i<s.size();i++){
            if(s[i] == '0') z++;
        }
        ans = z;
        for(int i=0;i<s.size();i++){
            if(s[i] == '0'){
                z--;
                ans = min(ans , z);
            }else{
                z++;
            }
        }
        return ans;
    }
};