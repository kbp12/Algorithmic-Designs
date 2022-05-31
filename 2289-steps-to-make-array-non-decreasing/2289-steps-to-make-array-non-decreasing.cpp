class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>dp(n,0);
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            while(st.size() && nums[i]>nums[st.top()]){
                dp[i] = max(dp[i]+1,dp[st.top()]);
                st.pop();
                ans = max(ans,dp[i]);
            }
            st.push(i);
        }
        return ans;
    }
};