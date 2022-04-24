class Solution {
public:
    int countLatticePoints(vector<vector<int>>& c) {
        int m = 201;
        vector<vector<int>>dp(m,vector<int>(m,0));
        int n = c.size();
        for(int i=0;i<201;i++){
            for(int j=0;j<201;j++){
                for(int k = 0;k<n;k++){
                    int d = (abs(i-c[k][0])*abs(i-c[k][0]))+(abs(j-c[k][1])*abs(j-c[k][1]));
                    if(d<=(c[k][2]*c[k][2])){
                        dp[i][j] = true;
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<201;i++){
            for(int j=0;j<201;j++){
                if(dp[i][j]) ans++;
            }
        }
        return ans;
    }
};