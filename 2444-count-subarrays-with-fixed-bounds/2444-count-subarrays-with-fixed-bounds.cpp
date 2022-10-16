class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        bool mini = false, maxi = false;
        int i = 0, mins = 0, maxs = 0;
        for(int j=0;j<nums.size();j++){
            if(nums[j] < minK or nums[j] > maxK){
                mini = false, maxi = false;
                i = j+1;
            }
            if(nums[j] == maxK){
                maxi = true;
                maxs = j;
            }
            if(nums[j] == minK){
                mini = true;
                mins = j;
            }
            if(mini and maxi){
                ans+=( min(mins , maxs) - i+1);
            }
        }
        return ans;
    }
};