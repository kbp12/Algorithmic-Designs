class Solution {
public:
    int ans;
    
    void dfs(vector<int>& nums , int target, int i, int sum){
        if(i == nums.size()){
            if( sum == target) ans++;
            return;
        }
        sum+=nums[i];
        dfs(nums , target , i+1 , sum);
        sum-=nums[i];
        sum-=nums[i];
        dfs(nums , target , i+1 , sum);
        return;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        ans = 0;
        dfs(nums , target , 0 , 0);
        return ans;
    }
};