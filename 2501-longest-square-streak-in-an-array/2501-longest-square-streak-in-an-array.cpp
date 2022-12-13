class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        unordered_map<long long , int>mpp;
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            long long temp = nums[i];
            temp = temp*temp;
            mpp[nums[i]] = max(mpp[temp] + 1 , mpp[nums[i]]);
            ans = max(ans , mpp[nums[i]]);
        }
        if(ans<2) return -1;
        return ans;
    }
};