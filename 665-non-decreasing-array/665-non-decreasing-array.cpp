class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool modified = false;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                if(modified){
                    return false;
                }else{
                    int temp = nums[i-1];
                    if(i==1){
                        nums[i-1] = INT_MIN;
                    }else{
                        nums[i-1] = nums[i-2];
                    }
                    if(nums[i]>=nums[i-1]){
                        modified = true;
                        continue;
                    }
                    nums[i-1] = temp;
                    if(i==n-1){
                        nums[i] = INT_MAX;
                    }else{
                        nums[i] = nums[i+1];
                    }
                    if(nums[i]>=nums[i-1]){
                        modified = true;
                        continue;
                    }
                    return false;
                }
            }
        }
        return true;
    }
};