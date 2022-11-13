class Solution {
public:
    
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>>check(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            check[i][i] = true;
            if(i!=n-1 and s[i] == s[i+1]){
                check[i][i+1] = true;
            }
        }
        for(int len = 3;len<=n;len++){
            for(int i=0;i<=(n-len);i++){
                int j = i+len-1;
                if(s[i] == s[j]){
                    check[i][j] = check[i+1][j-1];
                }
            }
        }
        vector<int>dp(n+1,0);
        for(int i=k;i<=n;i++){
            dp[i] = dp[i-1];
            for(int j=(i-k + 1);j>=1;j--){
                if(check[j-1][i-1]){
                    dp[i] = max(dp[i] , 1+dp[j-1]);
                }
            }
        }
        return *max_element(dp.begin() , dp.end());
    }
};