class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        long long ans = 1;
        int n = nums.size(), l = 1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                l++;
            }else{
                l = 1;
            }
            ans+=l;
        }
        return ans;
    }
};