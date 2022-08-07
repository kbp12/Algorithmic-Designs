class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int>dp(26,0);
        int n = s.size();
        for(char ch:s){
            int j = ch-'a';
            int ans = 0;
            for(int i=j;i>=max(0,j-k);i--){
                ans = max(ans,dp[i]+1);
            }
            for(int i=j;i<=min(25,j+k);i++){
                ans = max(ans,dp[i]+1);
            }
            dp[j] = ans;
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};