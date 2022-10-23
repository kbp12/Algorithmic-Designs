class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size() , rep , miss;
        for(int i=0;i<n;i++){
            int num = abs(nums[i]);
            if(nums[num-1]<0) rep = num;
            else    nums[num-1]*=-1;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0) {
                miss = i+1;
                break;
            }
        }
        return {rep , miss};
    }
};