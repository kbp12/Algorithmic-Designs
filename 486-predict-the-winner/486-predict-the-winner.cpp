class Solution {
public:
    int find(vector<int>& nums, int i, int j){
        if(i==j) return nums[i];
        if(i==j-1) return max(nums[i],nums[j]);
        return max(nums[i]+min(find(nums,i+2,j),find(nums,i+1,j-1)),nums[j]+min(find(nums,i+1,j-1),find(nums,i,j-2)));
    }   
    
    bool PredictTheWinner(vector<int>& nums) {
        int sum = 0;
        for(auto num:nums) sum+=num;
        int i=0, j=nums.size()-1;
        int ans = find(nums,i,j);
        if(ans>=(sum-ans)) return true;
        return false;
    }
};