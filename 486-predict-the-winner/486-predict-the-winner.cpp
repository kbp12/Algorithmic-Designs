class Solution {
public:
    int find(vector<int>& nums, int i, int j, int sum){
        if(i==j) return sum;
        if(i==j-1) return max(nums[i],nums[j]);
        return max(sum-find(nums,i+1,j,sum-nums[i]),sum-find(nums,i,j-1,sum-nums[j]));
    }   
    
    bool PredictTheWinner(vector<int>& nums) {
        int sum = 0;
        for(auto num:nums) sum+=num;
        int i=0, j=nums.size()-1;
        int ans = find(nums,i,j,sum);
        if(ans>=(sum-ans)) return true;
        return false;
    }
};