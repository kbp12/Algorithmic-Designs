class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int ans = 1;
        int prev = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                prev++;
            }else{
                prev = 0;
            }
            ans = max(ans,prev);
        }
        return ans;
    }
};