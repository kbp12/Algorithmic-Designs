class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1,0);
        dp[0] = 1;
        if(s[0]!='0') dp[1] = 1;
        for(int i=2;i<=n;i++){
            int way1 = 0, way2 = 0;
            if(s[i-1]!='0') way1 = dp[i-1];
            int a = stoi(s.substr(i-2,2));
            if(a<27 and s[i-2]!='0') way2 = dp[i-2];
            dp[i] = way1+way2;
        }
        return dp[n];
    }
};