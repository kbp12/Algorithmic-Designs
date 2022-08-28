class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_idx = nums[0];
        int i=0;
        while(i<n){
            if(nums[i]+i>max_idx)
                max_idx = nums[i]+i;
            if(max_idx >=n-1)
                return true;
            if(max_idx == i)
                return false;
            i++;
        }
        return true;
    }
};