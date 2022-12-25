class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int>ans(n);
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            ans[i] = i;
            for(int j=i;j>=0;j--){
                if(s[i]==s[j] && (i-j<2 || dp[j+1][i-1])){
                    dp[j][i] = true;
                    if(j==0){
                        ans[i] = 0;
                    }else{
                        ans[i] = min(ans[i],ans[j-1]+1);
                    }
                }
            }
        }
        return ans[n-1];
    }
};
