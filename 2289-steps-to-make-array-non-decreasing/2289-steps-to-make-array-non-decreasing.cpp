class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        stack<int>mono; // store elements in increasing order

        int max_count = 0;
        vector<int>dp(n , 0);
        for(int i=n-1;i>=0;i--){
            while(mono.size() and nums[mono.top()] < nums[i]){
                int j = mono.top();
                dp[i] = max(dp[i] + 1 , dp[j]);
                mono.pop();
            }
            max_count = max(max_count , dp[i]);
            mono.push(i);
        }
        return max_count;
    }
};