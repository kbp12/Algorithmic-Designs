class Solution {
public:
    int maxHeight(vector<vector<int>>& c){
        for(int i=0;i<c.size();i++)
            sort(c[i].begin(),c[i].end());
        c.push_back({0,0,0});
        sort(c.begin(),c.end());
        int n = c.size();
        vector<int>dp(n,0);
        int res = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(c[j][0]<=c[i][0] && c[j][1]<=c[i][1] && c[j][2]<=c[i][2]){
                    dp[i] = max(dp[i],dp[j]+c[i][2]);
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};