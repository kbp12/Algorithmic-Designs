class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& p) {
        int n = st.size();
        vector<vector<int>>trans(n,vector<int>(3));
        for(int i=0;i<n;i++){
            trans[i] = {et[i] , st[i] , p[i]};
        }
        sort(trans.begin() , trans.end());
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i] = dp[i-1];
            int l = 0, r = i-1;
            int idx = -1;
            while(l<=r){
                int m = l+(r-l)/2;
                int last = trans[m][0];
                if(last<=trans[i-1][1]){
                    idx = m;
                    l = m+1;
                }else{
                    r = m-1;
                }
            }
            dp[i] = max(dp[i] , dp[idx+1]+trans[i-1][2]);
            //cout<<dp[i]<<" ";
        }
        return dp[n];
    }
};