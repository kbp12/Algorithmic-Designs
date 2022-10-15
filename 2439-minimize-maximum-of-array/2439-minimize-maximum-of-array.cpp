class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long ans = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ans = max((sum + i) / (i + 1), ans);
        }
        return ans;
    }
};