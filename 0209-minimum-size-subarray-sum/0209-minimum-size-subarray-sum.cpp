class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,0);
        for(int i=0;i<n;i++){
            dp[i+1] = dp[i]+nums[i];
        }
        int ans = INT_MAX;
        int i=0,j=1;
        while(j<=n){
            if((dp[j]-dp[i])>=target){
                ans = min(ans,j-i);
                i++;
            }else
                j++;
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};