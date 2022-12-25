class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int ans=1, mod = 1e9+7;
        for(int i=0;i<n;i++) ans = (ans*2)%mod;
        vector<int>dp(k,0);
        dp[0] = 1;
        long long s = 0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            for(int j=k-1;j>=nums[i];j--){
                dp[j] = (dp[j] + dp[j - nums[i]])%mod;
            }
        }
        if(s<2*k) return 0;
        int sum = 0;
        for(int i=0;i<k;i++){
            sum = (sum+dp[i])%mod;
        }
        sum*=2;
        ans = (ans-sum+mod)%mod;
        return ans;
    }
};