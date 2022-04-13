class Solution {
public:
    int recur(vector<vector<int>>& dp, int idx, int m, vector<int>& sum){
        if(idx+2*m>=sum.size()-1) return sum[idx];
        int res = 0;
        for(int i=1;i<=2*m;i++){
             if(dp[idx+i][max(i,m)]==0) dp[idx+i][max(i,m)] = recur(dp,idx+i,max(i,m),sum);
            res = max(res,sum[idx]-dp[idx+i][max(i,m)]);
        }
        return res;
    }
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        //dp state is dp[i][j] stores max values Alice can get upto index i and with x as j
        vector<vector<int>>dp(n,vector<int>(n,0));
        vector<int>sum(n+1,0);
        for(int i=n-1;i>=0;i--) sum[i]=sum[i+1]+piles[i];
        return recur(dp,0,1,sum);
    }
};