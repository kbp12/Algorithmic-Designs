class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size(), m = pizza[0].size(), mod = 1e9+7;
        vector<vector<int>>suff(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            int c = 0;
            for(int j=m-1;j>=0;j--){
                if(pizza[i][j] == 'A' ) c++; 
                suff[i][j] = suff[i+1][j] + c;
            }
        }
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1)));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(suff[i][j]) dp[i][j][1] = 1;
                for(int kk=2;kk<=k;kk++){
                    for(int x=i+1;x<n;x++){
                        if(suff[i][j] == suff[x][j]) continue;
                        if(suff[x][j]==0) break;
                        dp[i][j][kk] = (dp[i][j][kk]+dp[x][j][kk-1])%mod;
                    }
                    for(int y=j+1;y<m;y++){
                        if(suff[i][j] == suff[i][y]) continue;
                        if(suff[i][y] == 0) break;
                        dp[i][j][kk] = (dp[i][j][kk] + dp[i][y][kk-1])%mod;
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};