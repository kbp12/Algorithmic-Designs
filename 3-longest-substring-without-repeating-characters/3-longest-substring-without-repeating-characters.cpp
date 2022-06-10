class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), i = 0, ans = 0;
        vector<int>dp(256,-1);
        for(int j=0;j<n;j++){
            i = max(i,dp[s[j]]+1);
            dp[s[j]] = j;
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};