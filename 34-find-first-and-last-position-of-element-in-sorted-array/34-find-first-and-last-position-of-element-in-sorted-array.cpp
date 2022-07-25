class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i =0, j = n-1 , m;
        int l = -1, r = -1;
        while(i<=j){
            m = i+(j-i)/2;
            if(nums[m]==target){
                l = m;
                j = m-1;
            }else if(nums[m]<target){
                i = m+1;
            }else{
                j = m-1;
            }
        }
        i=0, j = n-1;
        while(i<=j){
            m = i+(j-i)/2;
            if(nums[m]==target){
                r = m;
                i = m+1;
            }else if(nums[m]<target){
                i = m+1;
            }else{
                j = m-1;
            }
        }
        return {l,r};
    }
};