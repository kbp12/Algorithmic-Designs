class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i=n-2;i>=0;i--){
            int div = nums[i]/nums[i+1];
            int rem = nums[i]%nums[i+1];
            if(div==0){
                continue;
            }
            if(rem==0){
                ans+=div-1;
                nums[i] = nums[i+1];
            }else{
                ans+=div;
                int temp = nums[i]/(div+1);
                nums[i] = min({nums[i+1]-1,temp});
            }
        }
        return ans;
    }
};