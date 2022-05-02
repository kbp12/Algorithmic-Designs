class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = nums.size()-1, i=0;
        while(i<j){
            if(nums[i]%2 && nums[j]%2==0){
                swap(nums[i],nums[j]);
                i++;j--;
            }else if(nums[i]%2){
                j--;
            }else if(nums[j]%2==0){
                i++;
            }else{
                i++; j--;
            }
        }
        return nums;
    }
};