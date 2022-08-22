class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int j=0,k=0;
        for(int i=1;i<n;i++){
            if(nums[i]>=nums[j]){
                j = i;
            }
            if(nums[i]<nums[k]){
                k = i;
            }
        }
        if(j<k){
            return k+(n-1-j)-1; 
        }
        return k+n-1-j;
    }
};