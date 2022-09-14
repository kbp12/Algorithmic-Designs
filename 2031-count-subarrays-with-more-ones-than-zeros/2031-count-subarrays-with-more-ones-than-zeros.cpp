class Solution {
public:
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        int MOD = 1000000007;
        int sum = 0;
        vector<int> dp = {0, 0};
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0;
        for (int num : nums) {
            std::vector<int> dp_prev = dp;
            if (num == 1) {
                ++sum;
            } else {
                --sum;
            }
            dp[0] = mp[sum];
            if (num == 1) {
                dp[1] = (dp_prev[0] + dp_prev[1] + 1) % MOD;
            } else if (num == 0) {
                dp[1] = (dp_prev[1] - dp[0] + MOD) % MOD;
            }
            ++mp[sum];
            ans = (ans + dp[1]) % MOD;
        }
        return ans;
    }
};