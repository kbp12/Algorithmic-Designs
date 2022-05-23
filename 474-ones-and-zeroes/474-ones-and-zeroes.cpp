class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int k=0;k<s;k++){
            int a=0,b=0;
            for(auto it:strs[k]){
                if(it=='0')a++;
                else b++;
            }
            for(int i=m;i>=a;i--){
                for(int j=n;j>=b;j--){
                    dp[i][j] = max(dp[i][j],dp[i-a][j-b]+1);
                }
            }
            // for(int i=0;i<=m;i++){
            //     for(int j=0;j<=n;j++){
            //         cout<<dp[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
        }
        return dp[m][n];
    }
};