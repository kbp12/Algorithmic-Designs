class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {
        int n = nums.size();
        vector<long long>dp(n,LONG_MAX);
        dp[0] = 0;
        vector<long long>one, two;
        for(int i=0;i<n;i++){
            while(one.size() and nums[i]>=nums[one.back()]){
                dp[i] = min(dp[i],dp[one.back()]+costs[i]);
                one.pop_back();
            }
            while(two.size() and nums[i]<nums[two.back()]){
                dp[i] = min(dp[i],dp[two.back()]+costs[i]);
                two.pop_back();
            }
            one.push_back(i); 
            two.push_back(i);
        }
        return dp[n-1];
    }
};

