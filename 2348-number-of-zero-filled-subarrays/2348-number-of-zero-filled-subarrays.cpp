class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0, c = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                c++;
            }else{
                ans+= (c*(c+1))/2;
                c = 0;
            }
        }
        ans+= (c*(c+1))/2;
        return ans;
    }
};