class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        bool dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j] = false;
            }
        }
        for(auto c:corridors){
            dp[c[0]][c[1]] = 1;     dp[c[1]][c[0]] = 1;
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dp[i][j]){
                    for(int k=j+1;k<=n;k++){
                        if(dp[j][k] and dp[k][i]) ans++;
                    }
                }
            }
        }
        return ans;
    }
};