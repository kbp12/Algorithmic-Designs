class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i]+=n;
        }
        for(int i=0;i<n;i++){
            if(abs(nums[i])==2*n) continue;
            int a = abs(nums[i]) -n;
            nums[a] *= -1;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0) return i;
        }
        return n;
    }
};