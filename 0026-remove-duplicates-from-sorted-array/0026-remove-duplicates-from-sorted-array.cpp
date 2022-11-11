class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1)
            return n;
        int i=1;
        for(int j=1;j<n;j++){
            if(nums[j] == nums[i-1])
                continue;
            swap(nums[i],nums[j]);
            i++;
        }
        return i;
    }
};