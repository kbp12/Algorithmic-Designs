class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size() , ans=1, mod = 1e9+7;
        for(int i=0;i<n;i++) ans = (ans*2)%mod; // total number of ways
        
        vector<int>dp(k,0); // to store the number of ways of partition where sum < k
        dp[0] = 1;
        long long total_sum = 0;
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
            for(int j=k-1;j>=nums[i];j--){
                dp[j] = (dp[j] + dp[j - nums[i]])%mod;
            }
        }
        if(total_sum<2*k) return 0; 
        int sum_dp = 0;
        for(int i=0;i<k;i++){
            sum_dp = (sum_dp+dp[i])%mod;
        }
        ans = (ans-2*sum_dp+mod)%mod; // subtracting the invalid ways
        return ans;
    }
};