class Solution {
public:
    string shortestPalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        string str = s+"#"+s2;
        int m = str.length();
        vector<int>dp(m,0);
        int i =1, l = 0;
        while(i<m){
            if(str[i]==str[l]){
                l++;
                dp[i] = l; i++;
            }else{
                if(l == 0){
                    dp[i] = 0; i++;
                }else{
                    l = dp[l-1];
                }
            }
        }
        string str2 = s.substr(dp[m-1]);
        reverse(str2.begin(),str2.end());
        return str2+s;
    }
};