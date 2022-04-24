class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            int mini = nums[i], maxi = nums[i];
            for(int j=i;j<n;j++){
                mini = min(mini,nums[j]);
                maxi = max(maxi,nums[j]);
                ans+= (maxi-mini);
            }
        }
        return ans;
    }
};