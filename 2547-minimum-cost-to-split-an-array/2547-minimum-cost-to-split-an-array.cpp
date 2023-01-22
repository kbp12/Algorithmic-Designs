class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>dp(n+1 , INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            long long res = k;
            unordered_map<int,int>u;
            for(int j=i;j>=1;j--){
                u[nums[j-1]]++;
                if(u[nums[j-1]] == 2) res+=2;
                else if(u[nums[j-1]] > 2) res++;
                dp[i] = min(dp[i] , dp[j-1] + res);
            }
            u.clear();
        }
        return dp[n];
    }
};