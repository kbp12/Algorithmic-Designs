class Solution {
public:
    int longestSubsequence(string s, int k) {
        int value = 0, ans = 0, power = 1, count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') count++;
        }
        for(int i=s.length()-1;i>=0;i--){
            if(value+power>k) break;
            if(s[i]=='1'){
                ans++;
                value+=power;
            }
            power = power<<1;
        }
        return count+ans;
        int val = 0, cnt = 0, pow = 1;
    }
};