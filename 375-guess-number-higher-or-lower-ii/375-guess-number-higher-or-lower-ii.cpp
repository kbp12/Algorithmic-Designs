class Solution {
public:
    vector<vector<int>>dp;
    int range(int l, int r){
        if(l>=r){
            return 0;
        }
        if(dp[l][r]!=0) return dp[l][r];
        int ans = INT_MAX;
        for(int i=l;i<=r;i++){
            int temp = i+max(range(l,i-1),range(i+1,r));
            ans = min(ans,temp);
        }
        dp[l][r] = ans;
        return ans;
    }
    
    int getMoneyAmount(int n) {
        dp = vector<vector<int>>(n+1,vector<int>(n+1,0));
        return range(1,n);
    }
};