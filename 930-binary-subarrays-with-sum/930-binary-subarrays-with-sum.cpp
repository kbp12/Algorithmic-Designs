class Solution {
public:
    int subarrays(vector<int>nums, int goal){
        int n=nums.size(), count = 0, ans = 0;
        for(int i=0,j=0;j<n;j++){
            count+=nums[j];
            while(i<=j && count>goal){
                count-=nums[i];
                i++;
            }
            ans+= j-i+1;
        }
        return ans;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subarrays(nums,goal)-subarrays(nums,goal-1);
    }
};