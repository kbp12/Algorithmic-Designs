class Solution {
public:
    // int replacing(int n, vector<int>& dp, int s){
    //     int i =0;
    //     int j = s-1;
    //     while(i<=j){
    //         int mid = (i+j)/2;
    //         if(dp[mid]>=n){
    //             j = mid-1;
    //         }else{
    //             i = mid+1;
    //         }
    //     }
    //     return i;
    // }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp;
        dp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            int s = dp.size();
            if(nums[i]>dp[s-1]){
                dp.push_back(nums[i]);
            }else{
                int idx = lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
                dp[idx] = nums[i];
            }
        }
        
        // for(int i=0;i<dp.size();i++)
        //     cout<<dp[i]<<" ";
        
        return dp.size();
    }
};