class Solution {
public:
   vector<vector<int>>dp;
    int solve(vector<int>& arr, int idx, int cuts){
        if(idx==0 and cuts==0){
            return 0;
        }
        if(idx==0 or cuts==0) return 300006;
        if(dp[idx][cuts]!=300006) return dp[idx][cuts];
        int maxi = arr[idx-1];
        int ans = INT_MAX;
        for(int dd = cuts;dd>0;dd--){
            for(int j=idx;j>=cuts;j--){
                maxi = max(maxi , arr[j-1]);
                ans = min( ans , maxi + solve(arr,j-1,cuts-1));
            }
        }
        return dp[idx][cuts] = ans;
    }
        
    int minDifficulty(vector<int>& arr, int d) {
        int n = arr.size();
        if(n<d) return -1;
        dp = vector<vector<int>>(305,vector<int>(11,300006));
        //this->d = d;
        return solve(arr,n,d);
        // dp[0][0] = 0;
        // for(int i=1;i<=n;i++){
        //     for(int dd=1;dd<=d;dd++){
        //         int maxi = arr[i-1];
        //         for(int j=i;j>=1;j--){
        //             maxi = max(maxi,arr[j-1]);
        //             dp[i][dd] = min(dp[i][dd] , dp[j-1][dd-1]+maxi);
        //         }
        //     }
        // }
        // return dp[n][d];
    }
};